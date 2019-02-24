#define MSGSUCC_COLOR 0x55ffaaff
#define MSGFAIL_COLOR 0xff55aaff
#define MSGDBUG_COLOR 0xaa5555ff
#define MSGCMDS_COLOR 0xafcfafff
#define MSGTITL_COLOR 0xcfffcfff

new WordBinaryCrossSum[65536];//1 byte = 8 bits, 1 word == 2 bytes == 16 bits == 65536 combinations of 0 upto 16 bits used . will be used twice later, to sum up 2*16 bits per fingerprint value
new FingerPrintTolerance=26;//the whole alphabet as tolerance is a bad idea, it will cause weird behavior at short names (when "abc" matches "xyz" with a tolerance of 6, hence the 6 differences)

new VehFP[212];//32 bits as vehicle fingerprint
new VehFPC[212];//cross sum (represents the bits used: "abc" are 3 bits used

new WepFP[48];//weapons
new WepFPC[48];

new PlayerFP[MAX_PLAYERS];//the fingerprint, using 1 cell (4 bytes)
new PlayerFPC[MAX_PLAYERS];//the cross-sum of all bits (max 32 indeed), its a sort of typo-tolerance value when the search strings FPC got subtracted (XOR-ed)
new PlayerName[MAX_PLAYERS][MAX_PLAYER_NAME];//storing them in an array will avoid using lots of GetPlayerName() in loops

//searching vehicle names like "hotring racer", "monster", "PD", "maverick" is possible due to the numbers added to some names, atm its the vulnerable spot of the algorithm (you need to search an almost exact name like "maverickpolice"
new VName[212][]={//the classic vehicle array, slightly modified (mosters, some trailers: added numbers 1 2 3 etc for easy searching)
	"Landstalker","Bravura","Buffalo","Linerunner","Pereniel","Sentinel","Dumper","Firetruck","Trashmaster","Stretch","Manana","Infernus",
	"Voodoo","Pony","Mule","Cheetah","Ambulance","Leviathan","Moonbeam","Esperanto","Taxi","Washington","Bobcat","Mr Whoopee","BF Injection",
	"Hunter","Premier","Enforcer","Securicar","Banshee","Predator","Bus","Rhino","Barracks","Hotknife","Article Trailer 1","Previon","Coach","Cabbie",
	"Stallion","Rumpo","RC Bandit","Romero","Packer","Monster 1","Admiral","Squalo","Seasparrow","Pizzaboy","Tram","Article Trailer 2","Turismo","Speeder",
	"Reefer","Tropic","Flatbed","Yankee","Caddy","Solair","Berkley's RC Van","Skimmer","PCJ-600","Faggio","Freeway","RC Baron","RC Raider",
	"Glendale","Oceanic","Sanchez","Sparrow","Patriot","Quad","Coastguard","Dinghy","Hermes","Sabre","Rustler","ZR-350","Walton","Regina",
	"Comet","BMX","Burrito","Camper","Marquis","Baggage","Dozer","Maverick","News Chopper","Rancher","FBI Rancher","Virgo","Greenwood",
	"Jetmax","Hotring Racer 1","Sandking","Blista Compact","Police Maverick","Boxville","Benson","Mesa","RC Goblin","Hotring Racer 2","Hotring Racer 3",
	"Bloodring Banger","Rancher","Super GT","Elegant","Journey","Bike","Mountain Bike","Beagle","Cropdust","Stunt","Tanker","RoadTrain",
	"Nebula","Majestic","Buccaneer","Shamal","Hydra","FCR-900","NRG-500","HPV-1000","Cement Truck","Tow Truck","Fortune","Cadrona","FBI Truck",
	"Willard","Forklift","Tractor","Combine","Feltzer","Remington","Slamvan","Blade","Freight","Streak","Vortex","Vincent","Bullet","Clover",
	"Sadler","Firetruck","Hustler","Intruder","Primo","Cargobob","Tampa","Sunrise","Merit","Utility","Nevada","Yosemite","Windsor","Monster 2",
	"Monster 3","Uranus","Jester","Sultan","Stratum","Elegy","Raindance","RC Tiger","Flash","Tahoma","Savanna","Bandito","Freight Flat Trailer","Streak Trailer",
	"Kart","Mower","Duneride","Sweeper","Broadway","Tornado","AT-400","DFT-30","Huntley","Stafford","BF-400","Newsvan","Tug","Petrol Trailer","Emperor",
	"Wayfarer","Euros","Hotdog","Club","Freight Box Trailer","Article Trailer 3","Andromada","Dodo","RC Cam","Launch","Police Car (LSPD)","Police Car (SFPD)",
	"Police Car (LVPD)","Police Ranger","Picador","S.W.A.T. Van","Alpha","Phoenix","Glendale","Sadler","Baggage Trailer 1","Baggage Trailer 2",
	"Tug Stairs Trailer","Boxville","Farm Plow Trailer","Utility Trailer"
};

/*
ignore that list, i had to estimate which numerical characters are NOT meant to be put together in 1 bit, like the zr-350. ignoring the 0 (got its own bit), the 3 and 5 shouldnt be stored in the same bit..

vehicle names' numerical appearances - used for getting combinations to avoid in the <veh> specifier. the "0" deserves its own binary entry

-
600
3 50
-900
9500
1000
-400
-30
-400
()
.

4 bits matrix for holding 10 numbers - 0 gets its own bit:
147
258
369
0

and all other extra chars allowed in names, or at least, being recognized for a fingerprint
.-_()

*/

new WName[47][]={//weapons
	"Fist",
	"Brass Knuckles",
	"Golf Club",
	"Nightstick",
	"Knife",
	"Baseball Bat",
	"Shovel",
	"Pool Cue",
	"Katana",
	"Chainsaw",
	"Double Dildo",
	"Dildo",
	"Vibrator",
	"Silver Vibrator",
	"Flowers",
	"Cane",
	"Grenade",
	"Tear Gas",
	"Molotov Cocktail",
	"",
	"",
	"",
	"9mm",
	"Silences 9mm",
	"Desert Eagle",
	"Shotgun",
	"Sawnoff Shotgun",
	"Combat Shotgun",
	"Micro SMG",
	"MP5",
	"AK47",
	"M4",
	"Tec9",
	"Country Rifle",
	"Sniper Rifle",
	"Rocket Launcher",
	"HeatSeek Rocket Launcher",
	"Flamethrower",
	"Minigun",
	"Satchel Charge",
	"Detonator",
	"Spraycan",
	"Fire Extinguisher",
	"Camera",
	"Night Vision Goggles",
	"Thermal Goggles",
	"Parachute"
};

new WAllowed[]={//to make the loop shorter, this will be the array for pointing to valid (allowed) weapons - no gaps between. for now, all weapons are allowed.
	00,//"Fist",
	01,//"Brass Knuckles",
	02,//"Golf Club",
	03,//"Nightstick",
	04,//"Knife",
	05,//"Baseball Bat",
	06,//"Shovel",
	07,//"Pool Cue",
	08,//"Katana",
	09,//"Chainsaw",
	10,//"Double Dildo",
	11,//"Dildo",
	12,//"Vibrator",
	13,//"Silver Vibrator",
	14,//"Flowers",
	15,//"Cane",
	16,//"Grenade",
	17,//"Tear Gas",
	18,//"Molotov Cocktail",
/*	//19,//"",
	//20,//"",//dont uncomment those 3 lines - they are the reason why this ugly array is required. feel free to comment out forbidden weapons
	//21,//"",*/
	22,//"9mm",
	23,//"Silences 9mm",
	24,//"Desert Eagle",
	25,//"Shotgun",
	26,//"Sawnoff Shotgun",
	27,//"Combat Shotgun",
	28,//"Micro SMG",
	29,//"MP5",
	30,//"AK47",
	31,//"M4",
	32,//"Tec9",
	33,//"Country Rifle",
	34,//"Sniper Rifle",
	35,//"Rocket Launcher",
//	36,//"HeatSeek Rocket Launcher",//not synced
	37,//"Flamethrower",
	38,//"Minigun",
	39,//"Satchel Charge",
//	40,//"Detonator",//senseless without having placed a satchelcharge, which automatically gives you the detonator
	41,//"Spraycan",
	42,//"Fire Extinguisher",
	43,//"Camera",
//	44,//"Night Vision Goggles",//not synced
//	45,//"Thermal Goggles",//not synced
	46//,"Parachute"
};

stock FingerPrint(Name[]){
	new FP;
	new Lenght=strlen(Name);
	for(new p=0;p<Lenght;p++)
	{
		switch(Name[p])//set the bit accordingly to each character fond in the name
		{
			case 'a','A':
			{
				FP|=0b00000000000000000000000000000001;
			}
			case 'b','B':
			{
				FP|=0b00000000000000000000000000000010;
			}
			case 'c','C':
			{
				FP|=0b00000000000000000000000000000100;
			}
			case 'd','D':
			{
				FP|=0b00000000000000000000000000001000;
			}
			case 'e','E':
			{
				FP|=0b00000000000000000000000000010000;
			}
			case 'f','F':
			{
				FP|=0b00000000000000000000000000100000;
			}
			case 'g','G':
			{
				FP|=0b00000000000000000000000001000000;
			}
			case 'h','H':
			{
				FP|=0b00000000000000000000000010000000;
			}
			case 'i','I':
			{
				FP|=0b00000000000000000000000100000000;
			}
			case 'j','J':
			{
				FP|=0b00000000000000000000001000000000;
			}
			case 'k','K':
			{
				FP|=0b00000000000000000000010000000000;
			}
			case 'l','L':
			{
				FP|=0b00000000000000000000100000000000;
			}
			case 'm','M':
			{
				FP|=0b00000000000000000001000000000000;
			}
			case 'n','N':
			{
				FP|=0b00000000000000000010000000000000;
			}
			case 'o','O':
			{
				FP|=0b00000000000000000100000000000000;
			}
			case 'p','P':
			{
				FP|=0b00000000000000001000000000000000;
			}
			case 'q','Q':
			{
				FP|=0b00000000000000010000000000000000;
			}
			case 'r','R':
			{
				FP|=0b00000000000000100000000000000000;
			}
			case 's','S':
			{
				FP|=0b00000000000001000000000000000000;
			}
			case 't','T':
			{
				FP|=0b00000000000010000000000000000000;
			}
			case 'u','U':
			{
				FP|=0b00000000000100000000000000000000;
			}
			case 'v','V':
			{
				FP|=0b00000000001000000000000000000000;
			}
			case 'w','W':
			{
				FP|=0b00000000010000000000000000000000;
			}
			case 'x','X':
			{
				FP|=0b00000000100000000000000000000000;
			}
			case 'y','Y':
			{
				FP|=0b00000001000000000000000000000000;
			}
			case 'z','Z':
			{
				FP|=0b00000010000000000000000000000000;
			}

			case '1','4','7':
			{
				FP|=0b00000100000000000000000000000000;
			}
			case '2','5','8':
			{
				FP|=0b00001000000000000000000000000000;
			}
			case '3','6','9':
			{
				FP|=0b00010000000000000000000000000000;
			}
			case '0':
			{
				FP|=0b00100000000000000000000000000000;
			}
			case '.','-','_','(',')':
			{
				FP|=0b01000000000000000000000000000000;
			}
		}
	}
	return FP;
}

CalculateVehicleFingerprints(){
	for(new vehicleid=0;vehicleid<212;vehicleid++)
	{
		VehFP[vehicleid]=FingerPrint(VName[vehicleid]);
		VehFPC[vehicleid]=WordBinaryCrossSum[VehFP[vehicleid]%256];
	}
	return 1;
}

CalculateWeaponFingerprints(){
	for(new weaponid=0;weaponid<47;weaponid++)
	{
		WepFP[weaponid]=FingerPrint(WName[weaponid]);
		WepFPC[weaponid]=WordBinaryCrossSum[WepFP[weaponid]%256];
	}
	return 1;
}

CalculateWordBinaryCrossSums(){//2^32 bits are too much to be calculated in a loop - 2*2^16 is ok, the resulting 16 bits (65536) are split up into 2x2^8 bits
	new BitsInByte[256]={
		0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,
		1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
		1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
		1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
		2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
		3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
		3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
		4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8
	};
	for(new b=0;b<65536;b++)
	{
		WordBinaryCrossSum[b]=BitsInByte[b>>8%0x100]+BitsInByte[b%0x100];//this 16bit variable will be used twice later, to fill up the 32 bits
	}
	return 1;
}

SSCANF:pla(string[]){//player: not yet an optimal replacement for the "u" specifier
	new TargetID;
	if(!sscanf(string,"d",TargetID))
	{
		if(IsPlayerConnected(TargetID))
		{
			return TargetID;
		}
	}
	new FP,FPC,FPref,FPDelta,FPCDeltaLowest=FingerPrintTolerance;
	FP=FingerPrint(string);
	FPC=WordBinaryCrossSum[FP>>16]+WordBinaryCrossSum[FP&0xffff];
	for(new id=0;id<MAX_PLAYERS;id++)
	{
		if(IsPlayerConnected(id))
		{
			FPDelta=FP^PlayerFP[id];
			FPC=WordBinaryCrossSum[FPDelta>>16]+WordBinaryCrossSum[FPDelta&0xffff];
			if(FPC<FPCDeltaLowest)
			{
				FPCDeltaLowest=FPC;
				TargetID=id;
//				new dstring[128];
//				format(dstring,sizeof(dstring),"%031b (%d)%s difference:%d",PlayerFP[id],id,PlayerName[id],FPC);
//				SendClientMessageToAll(MSGDBUG_COLOR,dstring);
			}
		}
	}
	return TargetID;
}

SSCANF:veh(string[]){//excellent for a /car /vehicle command: finds the best matching vehicle name to the inputstring, and returns the vehiclemodelid
	new ModelID=0,FP,FPC,FPref,FPDelta,FPCDeltaLowest=FingerPrintTolerance;
	if(!sscanf(string,"d",ModelID))//yes, it works: sscanf2 used in a sscanf2 custom specifier
	{
		if(ModelID>399 && ModelID<613)
		{
			return ModelID-400;
		}
	}
	{
		FP=FingerPrint(string);
		FPC=WordBinaryCrossSum[FP>>16]+WordBinaryCrossSum[FP&0xffff];
		for(new vmid=0;vmid<212;vmid++)
		{
			FPDelta=FP^VehFP[vmid];
			FPC=WordBinaryCrossSum[FPDelta>>16]+WordBinaryCrossSum[FPDelta&0xffff];
			if(FPC<FPCDeltaLowest)
			{
				FPCDeltaLowest=FPC;
				ModelID=vmid;
//				new dstring[128];
//				format(dstring,sizeof(dstring),"%031b (%d)%s difference:%d",VehFP[vmid],vmid,VName[vmid],FPC);
//				SendClientMessageToAll(MSGDBUG_COLOR,dstring);
			}
		}
	}
	return ModelID;
}

SSCANF:wep(string[]){//using the weapon array "withoput gaps", it finds any weapon
	new WeaponID=0,FP,FPC,FPref,FPDelta,FPCDeltaLowest=FingerPrintTolerance;
	FP=FingerPrint(string);
	FPC=WordBinaryCrossSum[FP>>16]+WordBinaryCrossSum[FP&0xffff];
	for(new wid=0;wid<sizeof(WAllowed);wid++)
	{
		FPDelta=FP^WepFP[WAllowed[wid]];
		FPC=WordBinaryCrossSum[FPDelta>>16]+WordBinaryCrossSum[FPDelta&0xffff];
		if(FPC<FPCDeltaLowest)
		{
			FPCDeltaLowest=FPC;
			WeaponID=WAllowed[wid];
//			new dstring[128];
//			format(dstring,sizeof(dstring),"%031b (%d)%s difference:%d",WepFP[WAllowed[wid]],WAllowed[wid],WName[WAllowed[wid]],FPC);
//			SendClientMessageToAll(MSGDBUG_COLOR,dstring);
		}
	}
	return WeaponID;
}

SSCANF:clp(string[]){//closest player to a specified playerid
//	SendClientMessageToAll(MSGDBUG_COLOR,string);
	new playerid;
	new TargetID=INVALID_PLAYER_ID;
	if(!sscanf(string,"k<pla>",playerid))
	{
		SendClientMessageToAll(MSGDBUG_COLOR,"processing players");
		new Float:MinDistanceYet=10000;
		new Float:pX,Float:pY,Float:pZ;
		GetPlayerPos(playerid,pX,pY,pZ);
		new Float:tpX,Float:tpY,Float:tpZ;
		new Float:dX,Float:dY,Float:dZ;
		for(new tid=0;tid<MAX_PLAYERS;tid++)
		{
			if(IsPlayerConnected(tid) && tid!=playerid)
			{
				GetPlayerPos(tid,tpX,tpY,tpZ);
				if(IsPlayerInRangeOfPoint(playerid,MinDistanceYet,tpX,tpY,tpZ)==1)
				{
					dX=pX-tpX;
					dY=pY-tpY;
					dZ=pZ-tpZ;
					MinDistanceYet=floatsqroot(dX*dX+dY*dY+dZ*dZ);
					TargetID=tid;
				}
			}
		}
	}
	return TargetID;
}

SSCANF:clv(string[]){//closest vehicle to a specified playerid
//	SendClientMessageToAll(MSGDBUG_COLOR,string);
	new playerid;
	new VehicleID;
	if(!sscanf(string,"k<pla>",playerid))
	{
		SendClientMessageToAll(MSGDBUG_COLOR,"processing vehicles");
		new Float:MinDistanceYet=10000;
		new pveh;
		new Float:pX,Float:pY,Float:pZ;
		if(IsPlayerInAnyVehicle(playerid))
		{
			pveh=GetPlayerVehicleID(playerid);
			GetVehiclePos(pveh,pX,pY,pZ);
		}
		else
		{
			GetPlayerPos(playerid,pX,pY,pZ);
		}
		new Float:vX,Float:vY,Float:vZ;
		new Float:dX,Float:dY,Float:dZ;
		for(new vid=0;vid<MAX_VEHICLES;vid++)
		{
			if(vid!=pveh)
			{
				GetVehiclePos(vid,vX,vY,vZ);
				if(IsPlayerInRangeOfPoint(playerid,MinDistanceYet,vX,vY,vZ)==1)
				{
					dX=pX-vX;
					dY=pY-vY;
					dZ=pZ-vZ;
					MinDistanceYet=floatsqroot(dX*dX+dY*dY+dZ*dZ);
					VehicleID=vid;
				}
			}
		}
	}
	return VehicleID;
}
