stock GetVehicleFriendlyName(vehicleid)
{
	new GVFNstring[56];
	format(GVFNstring, sizeof(GVFNstring), VehicleName[GetVehicleModel(vehicleid)-400]);
	return GVFNstring;
}
stock PlayerName(playerid)
{
	new Name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,Name,sizeof(Name));
	return Name;
}
// > Stocks | baltica
stock UsuCuenta(playerid)
{
    new string[128],pname[MAX_PLAYER_NAME];
    GetPlayerName(playerid,pname,sizeof(pname));
    format(string,sizeof(string),Cuentas,pname);
    return string;
}
stock Casas(casaid){
new Archivo[128];
format(Archivo, sizeof(Archivo), DIR_CASAS, casaid);
return Archivo;}
stock GuardarCasa(casaid){
new INI:File = INI_Open(Casas(casaid));
INI_SetTag(File,"Datos");
INI_WriteString(File,"Propietario",cInfo[casaid][cPro]);
INI_WriteInt(File,"Comprada",cInfo[casaid][cComp]);
INI_WriteFloat(File,"Coordenada X",cInfo[casaid][cx]);
INI_WriteFloat(File,"Coordenada Y",cInfo[casaid][cy]);
INI_WriteFloat(File,"Coordenada Z",cInfo[casaid][cz]);
INI_WriteFloat(File,"Int X",cInfo[casaid][ix]);
INI_WriteFloat(File,"Int Y",cInfo[casaid][iy]);
INI_WriteFloat(File,"Int Z",cInfo[casaid][iz]);
INI_WriteInt(File,"Casa ID",cInfo[casaid][cID]);
INI_WriteInt(File,"Cerradura",cInfo[casaid][cCerradura]);
INI_Close(File);
return 1;}
stock GCasa(){
for(new i;i<MAX_CASAS;i++){GuardarCasa(i);}
return 1;}
stock GuardarCuenta(playerid)
{
    new INI:File = INI_Open(UsuCuenta(playerid));
    INI_SetTag(File,"data");
    INI_WriteString(File,"Contrasena",Info[playerid][pLlave]);
    GetPlayerPos(playerid,Info[playerid][px],Info[playerid][py],Info[playerid][pz]);
    INI_WriteFloat(File,"PosicionX",Info[playerid][px]);
    INI_WriteFloat(File,"PosicionY",Info[playerid][py]);
    INI_WriteFloat(File,"PosicionZ",Info[playerid][pz]);
    INI_WriteInt(File,"Faccion",Info[playerid][pFac]);
    INI_WriteInt(File,"Administracion",Info[playerid][pAdmin]);
    INI_WriteInt(File,"AdminEF",Info[playerid][pAdminEF]);
	INI_WriteInt(File,"AdminES",Info[playerid][pAdminES]);
	INI_WriteInt(File,"AdminTech",Info[playerid][pAdminTech]);
    Info[playerid][pSkin]=GetPlayerSkin(playerid);
    INI_WriteInt(File,"Loteria",Info[playerid][pLot]);
    INI_WriteInt(File,"Ropa",Info[playerid][pSkin]);
    INI_WriteInt(File,"Rango",Info[playerid][pRang]);
    INI_WriteInt(File,"Trabajo",Info[playerid][pTrab]);
    GetPlayerHealth(playerid,Info[playerid][pVida]);
    GetPlayerArmour(playerid,Info[playerid][Chaleco]);
    INI_WriteFloat(File,"VidaJ",Info[playerid][pVida]);
    INI_WriteFloat(File,"ChalecoJ",Info[playerid][Chaleco]);
    Info[playerid][pMoney] = GetPlayerMoney(playerid);
    INI_WriteInt(File,"Dinero",Info[playerid][pMoney]);
    Info[playerid][pBuq] = GetPlayerWantedLevel(playerid);
    INI_WriteInt(File,"NivelDeBusqueda",Info[playerid][pBuq]);
	INI_WriteInt(File,"LlavesDelCoche",Info[playerid][pLlavesDeVeh]);
	INI_WriteInt(File,"LlavesCoche",Info[playerid][pVehLlaves]);
	INI_WriteInt(File,"Coche Lock",Info[playerid][pLockCar]);
 	INI_WriteInt(File,"Lock",Info[playerid][pLock]);
 	INI_WriteInt(File,"NivelVip",Info[playerid][pVIP]);
	INI_WriteInt(File,"Nivel",Info[playerid][pLevel]);
	INI_WriteInt(File,"ExperienciaN",Info[playerid][pLevelExp]);
	INI_WriteInt(File,"Muertes",Info[playerid][pMuertes]);
	INI_WriteInt(File,"Edad",Info[playerid][pEdad]);
	INI_WriteInt(File,"Ban",Info[playerid][pBan]);
	for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
	{
		new string3[64];
		format(string3, 64, "pv%dPosX",v);
		INI_WriteFloat(File,string3,PlayerVehicleInfo[playerid][v][pvPosX]);
		format(string3, 64, "pv%dPosY",v);
		INI_WriteFloat(File,string3,PlayerVehicleInfo[playerid][v][pvPosY]);
		format(string3, 64, "pv%dPosZ",v);
		INI_WriteFloat(File,string3,PlayerVehicleInfo[playerid][v][pvPosZ]);
		format(string3, 64, "pv%dPosAngle",v);
		INI_WriteFloat(File,string3,PlayerVehicleInfo[playerid][v][pvPosAngle]);
		format(string3, 64, "pv%dVirtualW",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvVW]);
		format(string3, 64, "pv%dModelId",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvModelId]);
		format(string3, 64, "pv%dLock",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvLock]);
		format(string3, 64, "pv%dLocked",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvLocked]);
		format(string3, 64, "pv%dPaintJob",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvPaintJob]);
		format(string3, 64, "pv%dColor1",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvColor1]);
		format(string3, 64, "pv%dColor2",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvColor2]);
		format(string3, 64, "pv%dPrice",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvPrice]);
		format(string3, 64, "pv%dTicket",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvTicket]);
		format(string3, 64, "pv%dWeapon0",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvWeapons][0]);
		format(string3, 64, "pv%dWeapon1",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvWeapons][1]);
		format(string3, 64, "pv%dWeapon2",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvWeapons][2]);
		format(string3, 64, "pv%dWepUpgrade",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvWepUpgrade]);
		format(string3, 64, "pv%dFuel",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvFuel]);
		format(string3, 64, "pv%dImpound",v);
		INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvImpounded]);
		format(string3, 64, "pv%dHealth",v);
		INI_WriteFloat(File,string3,PlayerVehicleInfo[playerid][v][pvHealth]);
		for(new m = 0; m < MAX_MODS; m++)
		{
		 	format(string3, 64, "pv%dMod%d", v, m);
			INI_WriteInt(File,string3,PlayerVehicleInfo[playerid][v][pvMods][m]);
		}
   	}
   	print("Guardado de cuenta");
    INI_Close(File);
    return 1;
}
LoadcDealerships()
{
	new idx, idx2;
	new string[128];
	new owner[MAX_PLAYER_NAME];
	new message[128];
	djAutocommit(false);
	//print("[DEBUG] Starting while ( fread( CDSInfo , Data , sizeof( Data ) ) )");
	while (idx < sizeof(CDSInfo))
	{
        format(string, sizeof(string), "%d/owned", idx);
		CDSInfo[idx][cdOwned] = djInt("cardealerships.json", string);
		format(string, sizeof(string), "%d/owner", idx);
		format(owner, sizeof(owner), "%s", dj("cardealerships.json", string));
		strmid(CDSInfo[idx][cdOwner], owner, 0, strlen(owner), 255);
		format(string, sizeof(string), "%d/entrance/x", idx);
		CDSInfo[idx][cdEntranceX] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/entrance/y", idx);
		CDSInfo[idx][cdEntranceY] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/entrance/z", idx);
		CDSInfo[idx][cdEntranceZ] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/exit/x", idx);
		CDSInfo[idx][cdExitX] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/exit/y", idx);
		CDSInfo[idx][cdExitY] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/exit/z", idx);
	    CDSInfo[idx][cdExitZ] = djFloat("cardealerships.json", string);
	    format(string, sizeof(string), "%d/message", idx);
		format(message, sizeof(message), "%s", dj("cardealerships.json", string));
		strmid(CDSInfo[idx][cdMessage], message, 0, strlen(message), 255);
		format(string, sizeof(string), "%d/till", idx);
		CDSInfo[idx][cdTill] = djInt("cardealerships.json", string);
		format(string, sizeof(string), "%d/interior", idx);
		CDSInfo[idx][cdInterior] = djInt("cardealerships.json", string);
		format(string, sizeof(string), "%d/vehiclespawn/x", idx);
		CDSInfo[idx][cdVehicleSpawn][0] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/vehiclespawn/y", idx);
		CDSInfo[idx][cdVehicleSpawn][1] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/vehiclespawn/z", idx);
		CDSInfo[idx][cdVehicleSpawn][2] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/vehiclespawn/a", idx);
		CDSInfo[idx][cdVehicleSpawn][3] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/radius", idx);
		CDSInfo[idx][cdRadius] = djFloat("cardealerships.json", string);
		format(string, sizeof(string), "%d/price", idx);
		CDSInfo[idx][cdPrice] = djInt("cardealerships.json", string);
		while (idx2 < MAX_DEALERSHIPVEHICLES)
		{
            format(string, sizeof(string), "%d/vehicleangle/%d", idx, idx2);
		    CDSInfo[idx][cdVehicleSpawnAngle][idx2] = djFloat("cardealerships.json", string);
		    format(string, sizeof(string), "%d/vehiclespawnx/%d", idx, idx2);
		    CDSInfo[idx][cdVehicleSpawnX][idx2] = djFloat("cardealerships.json", string);
		    format(string, sizeof(string), "%d/vehiclespawny/%d", idx, idx2);
		    CDSInfo[idx][cdVehicleSpawnY][idx2] = djFloat("cardealerships.json", string);
		    format(string, sizeof(string), "%d/vehiclespawnz/%d", idx, idx2);
		    CDSInfo[idx][cdVehicleSpawnZ][idx2] = djFloat("cardealerships.json", string);
		    format(string, sizeof(string), "%d/vehiclecost/%d", idx, idx2);
		    CDSInfo[idx][cdVehicleCost][idx2] = djInt("cardealerships.json", string);
		    format(string, sizeof(string), "%d/vehicletypes/%d", idx, idx2);
		    CDSInfo[idx][cdVehicleModel][idx2] = djInt("cardealerships.json", string);
		    idx2++;
		}
		idx2 = 0;
		idx++;
	}
	//print("[DEBUG] Starting while ( fread( CLOSE ARCHIVO , Data , sizeof( Data ) ) )");
	djAutocommit(true);
	return 1;
}

SavecDealership(id)
{
	new idx2;
	new string[128];
	//printf("Saving Concesionario %d.", id);
	//djAutocommit(false);
    format(string, sizeof(string), "%d/owned", id);
	djSetInt("cardealerships.json", string, CDSInfo[id][cdOwned]);
	format(string, sizeof(string), "%d/owner", id);
	djSet("cardealerships.json", string, CDSInfo[id][cdOwner]);
	format(string, sizeof(string), "%d/entrance/x", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdEntranceX]);
	format(string, sizeof(string), "%d/entrance/y", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdEntranceY]);
	format(string, sizeof(string), "%d/entrance/z", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdEntranceZ]);
	format(string, sizeof(string), "%d/exit/x", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdExitX]);
	format(string, sizeof(string), "%d/exit/y", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdExitY]);
	format(string, sizeof(string), "%d/exit/z", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdExitZ]);
	format(string, sizeof(string), "%d/message", id);
	djSet("cardealerships.json", string, CDSInfo[id][cdMessage]);
	format(string, sizeof(string), "%d/till", id);
	djSetInt("cardealerships.json", string, CDSInfo[id][cdTill]);
	format(string, sizeof(string), "%d/interior", id);
	djSetInt("cardealerships.json", string, CDSInfo[id][cdInterior]);
	format(string, sizeof(string), "%d/vehiclespawn/x", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdVehicleSpawn][0]);
	format(string, sizeof(string), "%d/vehiclespawn/y", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdVehicleSpawn][1]);
	format(string, sizeof(string), "%d/vehiclespawn/z", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdVehicleSpawn][2]);
	format(string, sizeof(string), "%d/vehiclespawn/a", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdVehicleSpawn][3]);
	format(string, sizeof(string), "%d/radius", id);
	djSetFloat("cardealerships.json", string, CDSInfo[id][cdRadius]);
	format(string, sizeof(string), "%d/price", id);
	djSetInt("cardealerships.json", string, CDSInfo[id][cdPrice]);
	while (idx2 < MAX_DEALERSHIPVEHICLES)
	{
        format(string, sizeof(string), "%d/vehicleangle/%d", id, idx2);
        djSetFloat("cardealerships.json", string, CDSInfo[id][cdVehicleSpawnAngle][idx2]);
	    format(string, sizeof(string), "%d/vehiclespawnx/%d", id, idx2);
	    djSetFloat("cardealerships.json", string, CDSInfo[id][cdVehicleSpawnX][idx2]);
	    format(string, sizeof(string), "%d/vehiclespawny/%d", id, idx2);
	    djSetFloat("cardealerships.json", string, CDSInfo[id][cdVehicleSpawnY][idx2]);
	    format(string, sizeof(string), "%d/vehiclespawnz/%d", id, idx2);
	    djSetFloat("cardealerships.json", string, CDSInfo[id][cdVehicleSpawnZ][idx2]);
	    format(string, sizeof(string), "%d/vehiclecost/%d", id, idx2);
	    djSetInt("cardealerships.json", string, CDSInfo[id][cdVehicleCost][idx2]);
	    format(string, sizeof(string), "%d/vehicletypes/%d", id, idx2);
	    djSetInt("cardealerships.json", string, CDSInfo[id][cdVehicleModel][idx2]);
	    idx2++;
	}
    //djAutocommit(true);
	return 1;
}
stock CreateCarDealership(Float: enx, Float: eny, Float: enz, Float: radius, price, message[])
{
	new dealershipid = GetFreeCarDealership();
	if(dealershipid == -1) return -1;
	new text_info[128];
	CDSInfo[dealershipid][cdEntranceX] = enx;
	CDSInfo[dealershipid][cdEntranceY] = eny;
	CDSInfo[dealershipid][cdEntranceZ] = enz;
	CDSInfo[dealershipid][cdRadius] = radius;
	CDSInfo[dealershipid][cdPrice] = price;
	strmid(CDSInfo[dealershipid][cdMessage], message, 0, strlen(message), 255);
	CDSInfo[dealershipid][cdPickupID] = CreateDynamicPickup(1239, 1, CDSInfo[dealershipid][cdEntranceX], CDSInfo[dealershipid][cdEntranceY], CDSInfo[dealershipid][cdEntranceZ], .interiorid = 0);
	format(text_info, sizeof(text_info),"Concesionario (%d) %s\nDueño: %s", dealershipid, CDSInfo[dealershipid][cdMessage], CDSInfo[dealershipid][cdPrice]);
    CDSInfo[dealershipid][cdTextLabel] = CreateDynamic3DTextLabel(text_info,Color_Bot,CDSInfo[dealershipid][cdEntranceX], CDSInfo[dealershipid][cdEntranceY], CDSInfo[dealershipid][cdEntranceZ]+0.75,3.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
    SavecDealership(dealershipid);
    return dealershipid;
}

stock DestroyCarDealership(dealershipid)
{
	new string[30];
	CDSInfo[dealershipid][cdEntranceX] = 0.0;
	CDSInfo[dealershipid][cdEntranceY] = 0.0;
	CDSInfo[dealershipid][cdEntranceZ] = 0.0;
	CDSInfo[dealershipid][cdRadius] = 0.0;
	CDSInfo[dealershipid][cdTill] = 0;
	CDSInfo[dealershipid][cdOwned] = 0;
	CDSInfo[dealershipid][cdPrice] = 0;
	format(string, sizeof(string), "Nadie");
	strmid(CDSInfo[dealershipid][cdOwner], string, 0, strlen(string), 255);
	format(string, sizeof(string), "Nada");
	strmid(CDSInfo[dealershipid][cdMessage], string, 0, strlen(string), 255);
	DestroyDynamic3DTextLabel(CDSInfo[dealershipid][cdTextLabel]);
	DestroyDynamicPickup(CDSInfo[dealershipid][cdPickupID]);
	CDSInfo[dealershipid][cdPickupID] = 0;
	CDSInfo[dealershipid][cdTextLabel] = Text3D:INVALID_3DTEXT_ID;
	CDSInfo[dealershipid][cdVehicleSpawn][0] = 0.0;
    CDSInfo[dealershipid][cdVehicleSpawn][1] = 0.0;
    CDSInfo[dealershipid][cdVehicleSpawn][2] = 0.0;
    CDSInfo[dealershipid][cdVehicleSpawn][3] = 0.0;
	for(new v = 0; v < MAX_DEALERSHIPVEHICLES; v++)
	{
		if (CDSInfo[dealershipid][cdVehicleModel][v] != 0)
		{
	        DestroyCarDealershipVehicle(dealershipid, v);
		}
	}
	SavecDealership(dealershipid);
}

stock GetFreeCarDealership()
{
    new
		i = 0;
	while (i < MAX_CARDEALERSHIPS && CDSInfo[i][cdEntranceX] != 0.0 && CDSInfo[i][cdEntranceY] != 0.0)
	{
		i++;
	}
	if (i == MAX_CARDEALERSHIPS) return -1;
	return i;

}

stock SetPlayerOwnerOfCD(playerid, dealershipid)
{
	new owner[MAX_PLAYER_NAME];
	CDSInfo[dealershipid][cdOwned] = 1;
	GetPlayerName(playerid, owner, sizeof(owner));
	strmid(CDSInfo[dealershipid][cdOwner], owner, 0, strlen(owner), 255);
	new text_info[128];
	format(text_info, sizeof(text_info),"Concesionario (%d) %s\nDueño: %s", dealershipid, CDSInfo[dealershipid][cdMessage], CDSInfo[dealershipid][cdOwner]);
	UpdateDynamic3DTextLabelText(CDSInfo[dealershipid][cdTextLabel], Color_Azul, text_info);
	SavecDealership(dealershipid);
}

SurfingCheck(vehicleid)
{
	foreach(Player, p)
	{
		if(GetPlayerSurfingVehicleID(p) == vehicleid)
		{
   			new Float:x, Float:y, Float:z;
			GetPlayerPos(p, x, y, z);
		    SetPVarFloat(p, "tempPosX", x);
			SetPVarFloat(p, "tempPosY", x);
			SetPVarFloat(p, "tempPosZ", x);

			SetTimerEx("SurfingFix", 2000, 0, "i", p);
		}
	}
}
Random(min, max)
{
    new a = random(max - min) + min;
    return a;
}
stock SellCarDealership(dealershipid)
{
	CDSInfo[dealershipid][cdOwned] = 0;
	CDSInfo[dealershipid][cdVehicleSpawn][0] = 0.0;
	CDSInfo[dealershipid][cdVehicleSpawn][1] = 0.0;
	CDSInfo[dealershipid][cdVehicleSpawn][2] = 0.0;
	CDSInfo[dealershipid][cdVehicleSpawn][3] = 0.0;
	strmid(CDSInfo[dealershipid][cdOwner], "Nadie", 0, MAX_PLAYER_NAME, 255);
	new text_info[128];
	format(text_info, sizeof(text_info),"Concesionario (%d) %s En Venta\nPrecio: %d", dealershipid, CDSInfo[dealershipid][cdMessage], CDSInfo[dealershipid][cdPrice]);
	UpdateDynamic3DTextLabelText(CDSInfo[dealershipid][cdTextLabel], Color_Bot, text_info);
	SavecDealership(dealershipid);
}

IsVehicleBusy(vehicleid) // The_Chaoz ¿?¿?¿
{
    for(new i; i<GetMaxPlayers(); i++)
    	if(IsPlayerConnected(i) && IsPlayerInVehicle(i, vehicleid))
    		return 1;
    return 0;
}

stock IsPlayerOwnerOfCD(playerid)
{
	new owner[MAX_PLAYER_NAME];
	GetPlayerName(playerid, owner, sizeof(owner));
	for(new d = 0; d < MAX_CARDEALERSHIPS; d++)
    {
	    if(strcmp(CDSInfo[d][cdOwner],owner, true ) == 0)
	    {
			return d;
		}
	}
	return -1;
}

stock IsPlayerOwnerOfCDEx(playerid, dealershipid)
{
	new owner[MAX_PLAYER_NAME];
	GetPlayerName(playerid, owner, sizeof(owner));
	if(strcmp(CDSInfo[dealershipid][cdOwner],owner, true ) == 0)
	{
	    return 1;
	}
	return 0;
}

stock CreateCarDealershipVehicle(dealershipid, modelid, Float: x, Float: y, Float: z, Float: a, price)
{
    new cdvehicleid = GetFreeCarDealershipVehicleId(dealershipid);
    if(cdvehicleid == -1) return -1;
    new text_info[128];
    CDSInfo[dealershipid][cdVehicleModel][cdvehicleid] = modelid;
    CDSInfo[dealershipid][cdVehicleCost][cdvehicleid] = price;
    CDSInfo[dealershipid][cdVehicleSpawnX][cdvehicleid] = x;
    CDSInfo[dealershipid][cdVehicleSpawnY][cdvehicleid] = y;
    CDSInfo[dealershipid][cdVehicleSpawnZ][cdvehicleid] = z;
    CDSInfo[dealershipid][cdVehicleSpawnAngle][cdvehicleid] = a;
    new carcreated = CreateVehicle(modelid, x, y, z, a, 0, 0, 6);
    format(text_info, sizeof(text_info), "%s En Venta | Precio: %d", GetVehicleName(carcreated), CDSInfo[dealershipid][cdVehicleCost][cdvehicleid]);
    CDSInfo[dealershipid][cdVehicleLabel][cdvehicleid] = CreateDynamic3DTextLabel(text_info,Color_Blanco,0.0, 0.0, 0.0,5.0,INVALID_PLAYER_ID,carcreated,1);
	CDSInfo[dealershipid][cdVehicleId][cdvehicleid] = carcreated;
	SavecDealership(cdvehicleid);
    return cdvehicleid;
}

stock DestroyCarDealershipVehicle(dealershipid, cdvehicleid)
{
    CDSInfo[dealershipid][cdVehicleModel][cdvehicleid] = 0;
    CDSInfo[dealershipid][cdVehicleCost][cdvehicleid] = 0;
    CDSInfo[dealershipid][cdVehicleSpawnX][cdvehicleid] = 0.0;
    CDSInfo[dealershipid][cdVehicleSpawnY][cdvehicleid] = 0.0;
    CDSInfo[dealershipid][cdVehicleSpawnZ][cdvehicleid] = 0.0;
    CDSInfo[dealershipid][cdVehicleSpawnAngle][cdvehicleid] = 0.0;
    DestroyDynamic3DTextLabel(CDSInfo[dealershipid][cdVehicleLabel][cdvehicleid]);
    DestroyVehicle(CDSInfo[dealershipid][cdVehicleId][cdvehicleid]);
    CDSInfo[dealershipid][cdVehicleLabel][cdvehicleid] = Text3D:INVALID_3DTEXT_ID;
    CDSInfo[dealershipid][cdVehicleId][cdvehicleid] = 0;
}

stock GetFreeCarDealershipVehicleId(dealershipid)
{
    new
		i = 0;
	while (i < MAX_DEALERSHIPVEHICLES && CDSInfo[dealershipid][cdVehicleModel][i] != 0)
	{
		i++;
	}
	if (i == MAX_DEALERSHIPVEHICLES) return -1;
	return i;

}

stock GetCarDealershipVehicleId(vehicleid)
{
    for(new d = 0; d < MAX_CARDEALERSHIPS; d++)
    {
        for(new v = 0; v < MAX_DEALERSHIPVEHICLES; v++)
        {
            if(CDSInfo[d][cdVehicleId][v] == vehicleid)
            {
                return v;
            }
		}
    }
    return -1;
}

stock GetCarDealershipId(vehicleid)
{
    for(new d = 0; d < MAX_CARDEALERSHIPS; d++)
    {
        for(new v = 0; v < MAX_DEALERSHIPVEHICLES; v++)
        {
            if(CDSInfo[d][cdVehicleId][v] == vehicleid)
            {
                return d;
            }
		}
    }
    return -1;
}
stock GetPlayerFreeVehicleId(playerid){
	for(new i; i < MAX_PLAYERVEHICLES; ++i){
		if(PlayerVehicleInfo[playerid][i][pvModelId] == 0) return i;
	}
	return -1;
}
stock CreatePlayerVehicle(playerid, playervehicleid, modelid, Float: x, Float: y, Float: z, Float: angle, color1, color2, price)
{
	if(PlayerVehicleInfo[playerid][playervehicleid][pvId] == INVALID_PLAYER_VEHICLE_ID)
	{
	    PlayerCars++;
        carsforplayer[playerid]++;
		PlayerVehicleInfo[playerid][playervehicleid][pvModelId] = modelid;
		PlayerVehicleInfo[playerid][playervehicleid][pvPosX] = x;
		PlayerVehicleInfo[playerid][playervehicleid][pvPosY] = y;
		PlayerVehicleInfo[playerid][playervehicleid][pvPosZ] = z;
		PlayerVehicleInfo[playerid][playervehicleid][pvPosAngle] = angle;
		PlayerVehicleInfo[playerid][playervehicleid][pvVW] = GetPlayerVirtualWorld(playerid);
		PlayerVehicleInfo[playerid][playervehicleid][pvColor1] = color1;
		PlayerVehicleInfo[playerid][playervehicleid][pvColor2] = color2;
		PlayerVehicleInfo[playerid][playervehicleid][pvPark] = 1;
		PlayerVehicleInfo[playerid][playervehicleid][pvPrice] = price;
		PlayerVehicleInfo[playerid][playervehicleid][pvFuel] = 1000;
		PlayerVehicleInfo[playerid][playervehicleid][pvLock] = 0;
		PlayerVehicleInfo[playerid][playervehicleid][pvImpounded] = 0;
		PlayerVehicleInfo[playerid][playervehicleid][pvHealth] = 1000.0;
		PlayerVehicleInfo[playerid][playervehicleid][pvSpawned] = 1;
		for(new m = 0; m < MAX_MODS; m++)
	    {
	    	PlayerVehicleInfo[playerid][playervehicleid][pvMods][m] = 0;
		}
		new carcreated = CreateVehicle(modelid,x,y,z,angle,color1,color2,-1);
		PlayerVehicleInfo[playerid][playervehicleid][pvId] = carcreated;
		SetVehicleVirtualWorld(carcreated, PlayerVehicleInfo[playerid][playervehicleid][pvVW]);
		//SetVehicleNumberPlate(carcreated, PlayerVehicleInfo[playerid][playervehicleid][pvNumberPlate]);
		return carcreated;
	}
	return INVALID_PLAYER_VEHICLE_ID;
}

stock DestroyPlayerVehicle(playerid, playervehicleid)
{
	if(PlayerVehicleInfo[playerid][playervehicleid][pvModelId])
	{
	    PlayerCars--;
	    carsforplayer[playerid]--;
		DestroyVehicle(PlayerVehicleInfo[playerid][playervehicleid][pvId]);
		PlayerVehicleInfo[playerid][playervehicleid][pvModelId] = 0;
		PlayerVehicleInfo[playerid][playervehicleid][pvPosX] = 0.0;
		PlayerVehicleInfo[playerid][playervehicleid][pvPosY] = 0.0;
		PlayerVehicleInfo[playerid][playervehicleid][pvPosZ] = 0.0;
		PlayerVehicleInfo[playerid][playervehicleid][pvPosAngle] = 0.0;
		PlayerVehicleInfo[playerid][playervehicleid][pvVW] = 0;
		PlayerVehicleInfo[playerid][playervehicleid][pvPaintJob] = -1;
		PlayerVehicleInfo[playerid][playervehicleid][pvColor1] = 126;
		PlayerVehicleInfo[playerid][playervehicleid][pvColor2] = 126;
		PlayerVehicleInfo[playerid][playervehicleid][pvPrice] = 0;
		PlayerVehicleInfo[playerid][playervehicleid][pvFuel] = 1000;
		PlayerVehicleInfo[playerid][playervehicleid][pvLock] = 0;
		PlayerVehicleInfo[playerid][playervehicleid][pvImpounded] = 0;
		PlayerVehicleInfo[playerid][playervehicleid][pvHealth] = 1000.0;
		PlayerVehicleInfo[playerid][playervehicleid][pvSpawned] = 0;
		VehicleFuel[PlayerVehicleInfo[playerid][playervehicleid][pvId]] = 1000;
		VehicleFuel[playervehicleid] = 1000;
		strcpy(PlayerVehicleInfo[playerid][playervehicleid][pvAllowPlayer], "Nadie", MAX_PLAYER_NAME);
	    PlayerVehicleInfo[playerid][playervehicleid][pvId] = INVALID_PLAYER_VEHICLE_ID;
	    if(PlayerVehicleInfo[playerid][playervehicleid][pvAllowedPlayerId] != INVALID_PLAYER_ID)
	    {
	        Info[PlayerVehicleInfo[playerid][playervehicleid][pvAllowedPlayerId]][pVehLlaves] = INVALID_PLAYER_VEHICLE_ID;
	        Info[PlayerVehicleInfo[playerid][playervehicleid][pvAllowedPlayerId]][pLlavesDeVeh] = INVALID_PLAYER_ID;
	    	PlayerVehicleInfo[playerid][playervehicleid][pvAllowedPlayerId] = INVALID_PLAYER_ID;
		}
	}
}
/*stock LoadCoches()
{
for(new playerid = 0,playerid<MAX_PLAYERS;playerid++)
{
	new playername[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playername, sizeof(playername));
	//printf(" Loading %s's vehicles.", playername);
	for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
    {
        if(PlayerVehicleInfo[playerid][v][pvImpounded] >= 2) PlayerVehicleInfo[playerid][v][pvImpounded] = 0;
        if(PlayerVehicleInfo[playerid][v][pvModelId] != 0 && PlayerVehicleInfo[playerid][v][pvImpounded] == 0)
        {
            PlayerCars++;
            carsforplayer[playerid]++;
			new carcreated = CreateVehicle(PlayerVehicleInfo[playerid][v][pvModelId], PlayerVehicleInfo[playerid][v][pvPosX], PlayerVehicleInfo[playerid][v][pvPosY], PlayerVehicleInfo[playerid][v][pvPosZ], PlayerVehicleInfo[playerid][v][pvPosAngle],PlayerVehicleInfo[playerid][v][pvColor1], PlayerVehicleInfo[playerid][v][pvColor2], -1);
			PlayerVehicleInfo[playerid][v][pvId] = carcreated;
			VehicleFuel[carcreated] = PlayerVehicleInfo[playerid][v][pvFuel];
			SetVehicleHealth(carcreated, PlayerVehicleInfo[playerid][v][pvHealth]);
			SetVehicleVirtualWorld(carcreated, PlayerVehicleInfo[playerid][v][pvVW]);
			//SetVehicleNumberPlate(carcreated, PlayerVehicleInfo[playerid][v][pvNumberPlate]);
			if(PlayerVehicleInfo[playerid][v][pvLocked] == 1) LockPlayerVehicle(playerid, PlayerVehicleInfo[playerid][v][pvId], PlayerVehicleInfo[playerid][v][pvLock]);
        }
        else if(PlayerVehicleInfo[playerid][v][pvModelId] == 0 && PlayerVehicleInfo[playerid][v][pvImpounded] != 0)
            PlayerVehicleInfo[playerid][v][pvImpounded] = 0;
    }
    LoadAllPlayerVehicleMods(playerid);
   }
}*/
stock LoadPlayerVehicles(playerid)
{
	new playername[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playername, sizeof(playername));
	//printf(" Loading %s's vehicles.", playername);
	for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
    {
        if(PlayerVehicleInfo[playerid][v][pvImpounded] >= 2) PlayerVehicleInfo[playerid][v][pvImpounded] = 0;
        if(PlayerVehicleInfo[playerid][v][pvModelId] != 0 && PlayerVehicleInfo[playerid][v][pvImpounded] == 0)
        {
            PlayerCars++;
            carsforplayer[playerid]++;
			new carcreated = CreateVehicle(PlayerVehicleInfo[playerid][v][pvModelId], PlayerVehicleInfo[playerid][v][pvPosX], PlayerVehicleInfo[playerid][v][pvPosY], PlayerVehicleInfo[playerid][v][pvPosZ], PlayerVehicleInfo[playerid][v][pvPosAngle],PlayerVehicleInfo[playerid][v][pvColor1], PlayerVehicleInfo[playerid][v][pvColor2], -1);
			PlayerVehicleInfo[playerid][v][pvId] = carcreated;
			VehicleFuel[carcreated] = PlayerVehicleInfo[playerid][v][pvFuel];
			SetVehicleHealth(carcreated, 1000);
			SetVehicleVirtualWorld(carcreated, PlayerVehicleInfo[playerid][v][pvVW]);
			//SetVehicleNumberPlate(carcreated, PlayerVehicleInfo[playerid][v][pvNumberPlate]);
			if(PlayerVehicleInfo[playerid][v][pvLocked] == 1) LockPlayerVehicle(playerid, PlayerVehicleInfo[playerid][v][pvId], PlayerVehicleInfo[playerid][v][pvLock]);
        }
        else if(PlayerVehicleInfo[playerid][v][pvModelId] == 0 && PlayerVehicleInfo[playerid][v][pvImpounded] != 0)
            PlayerVehicleInfo[playerid][v][pvImpounded] = 0;
    }
    LoadAllPlayerVehicleMods(playerid);
}

stock UnloadPlayerVehicles(playerid)
{
    new playername[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playername, sizeof(playername));
	//printf(" Unloading %s's vehicles.", playername);
	for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
    {
        if(PlayerVehicleInfo[playerid][v][pvImpounded] >= 2) PlayerVehicleInfo[playerid][v][pvImpounded] = 0;
        if(PlayerVehicleInfo[playerid][v][pvId] != INVALID_PLAYER_VEHICLE_ID && PlayerVehicleInfo[playerid][v][pvImpounded] == 0)
        {
            PlayerCars--;
            carsforplayer[playerid]--;
            if(LockStatus[PlayerVehicleInfo[playerid][v][pvId]] != 0) LockStatus[PlayerVehicleInfo[playerid][v][pvId]] = 0;
            UpdatePlayerVehicleMods(playerid, v);
			DestroyVehicle(PlayerVehicleInfo[playerid][v][pvId]);
			VehicleFuel[PlayerVehicleInfo[playerid][v][pvId]] = 1000;
			PlayerVehicleInfo[playerid][v][pvId] = INVALID_PLAYER_VEHICLE_ID;
			if(PlayerVehicleInfo[playerid][v][pvAllowedPlayerId] != INVALID_PLAYER_ID)
	    	{
	    	    Info[PlayerVehicleInfo[playerid][v][pvAllowedPlayerId]][pVehLlaves] = INVALID_PLAYER_VEHICLE_ID;
	    	    Info[PlayerVehicleInfo[playerid][v][pvAllowedPlayerId]][pLlavesDeVeh] = INVALID_PLAYER_ID;
	    		PlayerVehicleInfo[playerid][v][pvAllowedPlayerId] = INVALID_PLAYER_ID;
			}
        }
    }
}

stock RegisterVehicleNumberPlate(vehicleid, sz_NumPlate[])
{
	new
	    Float: a_CarPos[4], fuel; // X, Y, Z, Z Angle, Fuel

	GetVehiclePos(vehicleid, a_CarPos[0], a_CarPos[1], a_CarPos[2]);
	GetVehicleZAngle(vehicleid, a_CarPos[3]);
	fuel = VehicleFuel[vehicleid];
	//SetVehicleNumberPlate(vehicleid, sz_NumPlate);
	SetVehicleToRespawn(vehicleid);
	//SetVehicleToRespawn(vehicleid);
	SetVehiclePos(vehicleid, a_CarPos[0], a_CarPos[1], a_CarPos[2]);
	SetVehicleZAngle(vehicleid, a_CarPos[3]);
	VehicleFuel[vehicleid] = fuel;
	return 1;
}

stock UpdatePlayerVehicleParkPosition(playerid, playervehicleid, Float:newx, Float:newy, Float:newz, Float:newangle, Float:health)
{
    new playername[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playername, sizeof(playername));
	if(PlayerVehicleInfo[playerid][playervehicleid][pvId] != INVALID_PLAYER_VEHICLE_ID)
	{
		 new Float:oldx, Float:oldy, Float:oldz, oldfuel;
		 oldx = PlayerVehicleInfo[playerid][playervehicleid][pvPosX];
		 oldy = PlayerVehicleInfo[playerid][playervehicleid][pvPosY];
		 oldz = PlayerVehicleInfo[playerid][playervehicleid][pvPosZ];
		 if(oldx == newx && oldy == newy && oldz == newz) return 0;
		 PlayerVehicleInfo[playerid][playervehicleid][pvPosX] = newx;
		 PlayerVehicleInfo[playerid][playervehicleid][pvPosY] = newy;
		 PlayerVehicleInfo[playerid][playervehicleid][pvPosZ] = newz;
		 PlayerVehicleInfo[playerid][playervehicleid][pvPosAngle] = newangle;
		 PlayerVehicleInfo[playerid][playervehicleid][pvVW] = GetVehicleVirtualWorld(PlayerVehicleInfo[playerid][playervehicleid][pvId]);
		 oldfuel = VehicleFuel[PlayerVehicleInfo[playerid][playervehicleid][pvId]];
		 VehicleFuel[PlayerVehicleInfo[playerid][playervehicleid][pvId]] = 1000;
		 UpdatePlayerVehicleMods(playerid, playervehicleid);
		 DestroyVehicle(PlayerVehicleInfo[playerid][playervehicleid][pvId]);
		 new carcreated = CreateVehicle(PlayerVehicleInfo[playerid][playervehicleid][pvModelId], PlayerVehicleInfo[playerid][playervehicleid][pvPosX], PlayerVehicleInfo[playerid][playervehicleid][pvPosY], PlayerVehicleInfo[playerid][playervehicleid][pvPosZ],
		 PlayerVehicleInfo[playerid][playervehicleid][pvPosAngle],PlayerVehicleInfo[playerid][playervehicleid][pvColor1], PlayerVehicleInfo[playerid][playervehicleid][pvColor2], -1);
   		 SetVehicleVirtualWorld(carcreated, PlayerVehicleInfo[playerid][playervehicleid][pvVW]);
		 PlayerVehicleInfo[playerid][playervehicleid][pvId] = carcreated;
         VehicleFuel[carcreated] = oldfuel;
         SetVehicleHealth(carcreated, health);
		 if(PlayerVehicleInfo[playerid][playervehicleid][pvLocked] == 1) LockPlayerVehicle(playerid, PlayerVehicleInfo[playerid][playervehicleid][pvId], PlayerVehicleInfo[playerid][playervehicleid][pvLock]);
         LoadPlayerVehicleMods(playerid, playervehicleid);
         return 1;
	}
	return 0;
}

stock UpdatePlayerVehicleMods(playerid, playervehicleid)
{
	if(PlayerVehicleInfo[playerid][playervehicleid][pvImpounded] == 0) {
		new playername[MAX_PLAYER_NAME];
		GetPlayerName(playerid, playername, sizeof(playername));
		new carid = PlayerVehicleInfo[playerid][playervehicleid][pvId];
		new exhaust, frontbumper, rearbumper, roof, spoilers, sideskirt1,
			sideskirt2, wheels, hydraulics, nitro, hood, lamps, stereo, ventright, ventleft;
		exhaust = GetVehicleComponentInSlot(carid, CARMODTYPE_EXHAUST);
		frontbumper = GetVehicleComponentInSlot(carid, CARMODTYPE_FRONT_BUMPER);
		rearbumper = GetVehicleComponentInSlot(carid, CARMODTYPE_REAR_BUMPER);
		roof = GetVehicleComponentInSlot(carid, CARMODTYPE_ROOF);
		spoilers = GetVehicleComponentInSlot(carid, CARMODTYPE_SPOILER);
		sideskirt1 = GetVehicleComponentInSlot(carid, CARMODTYPE_SIDESKIRT);
		sideskirt2 = GetVehicleComponentInSlot(carid, CARMODTYPE_SIDESKIRT);
		wheels = GetVehicleComponentInSlot(carid, CARMODTYPE_WHEELS);
		hydraulics = GetVehicleComponentInSlot(carid, CARMODTYPE_HYDRAULICS);
		nitro = GetVehicleComponentInSlot(carid, CARMODTYPE_NITRO);
		hood = GetVehicleComponentInSlot(carid, CARMODTYPE_HOOD);
		lamps = GetVehicleComponentInSlot(carid, CARMODTYPE_LAMPS);
		stereo = GetVehicleComponentInSlot(carid, CARMODTYPE_STEREO);
		ventright = GetVehicleComponentInSlot(carid, CARMODTYPE_VENT_RIGHT);
		ventleft = GetVehicleComponentInSlot(carid, CARMODTYPE_VENT_LEFT);
		if(spoilers >= 1000)    PlayerVehicleInfo[playerid][playervehicleid][pvMods][0] = spoilers;
		if(hood >= 1000)        PlayerVehicleInfo[playerid][playervehicleid][pvMods][1] = hood;
		if(roof >= 1000)        PlayerVehicleInfo[playerid][playervehicleid][pvMods][2] = roof;
		if(sideskirt1 >= 1000)  PlayerVehicleInfo[playerid][playervehicleid][pvMods][3] = sideskirt1;
		if(lamps >= 1000)       PlayerVehicleInfo[playerid][playervehicleid][pvMods][4] = lamps;
		if(nitro >= 1000)       PlayerVehicleInfo[playerid][playervehicleid][pvMods][5] = nitro;
		if(exhaust >= 1000)     PlayerVehicleInfo[playerid][playervehicleid][pvMods][6] = exhaust;
		if(wheels >= 1000)      PlayerVehicleInfo[playerid][playervehicleid][pvMods][7] = wheels;
		if(stereo >= 1000)      PlayerVehicleInfo[playerid][playervehicleid][pvMods][8] = stereo;
		if(hydraulics >= 1000)  PlayerVehicleInfo[playerid][playervehicleid][pvMods][9] = hydraulics;
		if(frontbumper >= 1000) PlayerVehicleInfo[playerid][playervehicleid][pvMods][10] = frontbumper;
		if(rearbumper >= 1000)  PlayerVehicleInfo[playerid][playervehicleid][pvMods][11] = rearbumper;
		if(ventright >= 1000)   PlayerVehicleInfo[playerid][playervehicleid][pvMods][12] = ventright;
		if(ventleft >= 1000)    PlayerVehicleInfo[playerid][playervehicleid][pvMods][13] = ventleft;
		if(sideskirt2 >= 1000)  PlayerVehicleInfo[playerid][playervehicleid][pvMods][14] = sideskirt2;
	}
}

stock LoadPlayerVehicleMods(playerid, playervehicleid)
{
	if(PlayerVehicleInfo[playerid][playervehicleid][pvImpounded] == 0 && PlayerVehicleInfo[playerid][playervehicleid][pvSpawned]== 1)
	{
		//printf(" Cargando mods del jugador ID #%d.", playerid);
		new paintjob = PlayerVehicleInfo[playerid][playervehicleid][pvPaintJob];
		new color1 = PlayerVehicleInfo[playerid][playervehicleid][pvColor1];
		new color2 = PlayerVehicleInfo[playerid][playervehicleid][pvColor2];
		if(PlayerVehicleInfo[playerid][playervehicleid][pvPaintJob] != -1)
		{
			 ChangeVehiclePaintjob(PlayerVehicleInfo[playerid][playervehicleid][pvId], paintjob);
			 ChangeVehicleColor(PlayerVehicleInfo[playerid][playervehicleid][pvId], color1, color2);
		}
		for(new m = 0; m < MAX_MODS; m++)
		{
			AddVehicleComponent(PlayerVehicleInfo[playerid][playervehicleid][pvId], PlayerVehicleInfo[playerid][playervehicleid][pvMods][m]);
		}
	}
}

stock LoadAllPlayerVehicleMods(playerid)
{
	//print(" Modificaciones de todos los autos cargadas.");
	for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
    {
        if(PlayerVehicleInfo[playerid][v][pvModelId] != 0 && PlayerVehicleInfo[playerid][v][pvImpounded] == 0)
        {
            new paintjob = PlayerVehicleInfo[playerid][v][pvPaintJob];
        	new color1 = PlayerVehicleInfo[playerid][v][pvColor1];
	        new color2 = PlayerVehicleInfo[playerid][v][pvColor2];
            if(PlayerVehicleInfo[playerid][v][pvPaintJob] != -1)
	        {
                ChangeVehiclePaintjob(PlayerVehicleInfo[playerid][v][pvId], paintjob);
	        }
	        ChangeVehicleColor(PlayerVehicleInfo[playerid][v][pvId], color1, color2);
	        for(new m = 0; m < MAX_MODS; m++)
	        {
  	        	AddVehicleComponent(PlayerVehicleInfo[playerid][v][pvId], PlayerVehicleInfo[playerid][v][pvMods][m]);
	        }
		}
	}
}
stock GetPlayerVehicle(playerid, vehicleid)
{
	if(!IsPlayerConnected(playerid)) return -1;
	if(!GetVehicleModel(vehicleid)) return -1;
    for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
    {
        if(PlayerVehicleInfo[playerid][v][pvId] == vehicleid)
        {
            return v;
        }
    }
    return -1;
}

stock GetDistancePlayerVeh(playerid, veh) {

	new
	    Float:Floats[7];

	GetPlayerPos(playerid, Floats[0], Floats[1], Floats[2]);
	GetVehiclePos(veh, Floats[3], Floats[4], Floats[5]);
	Floats[6] = floatsqroot((Floats[3]-Floats[0])*(Floats[3]-Floats[0])+(Floats[4]-Floats[1])*(Floats[4]-Floats[1])+(Floats[5]-Floats[2])*(Floats[5]-Floats[2]));

	return floatround(Floats[6]);
}

stock doesVehicleExist(vehicleid) {

    if(GetVehicleModel(vehicleid) >= 400) {
		return 1;
	}
	return 0;
}
LockPlayerVehicle(ownerid, carid, type)
{
	new v = GetPlayerVehicle(ownerid, carid);
	if(PlayerVehicleInfo[ownerid][v][pvId] == carid && type == 3)
	{
	    LockStatus[carid] = 1;
	    vehicle_lock_doors(carid);
	}
}
vehicle_lock_doors(vehicle)
{
	new
		vParamArr[7];
	GetVehicleParamsEx(vehicle, vParamArr[0], vParamArr[1], vParamArr[2], vParamArr[3], vParamArr[4], vParamArr[5], vParamArr[6]);
	return SetVehicleParamsEx(vehicle, vParamArr[0], vParamArr[1], vParamArr[2], VEHICLE_PARAMS_ON, vParamArr[4], vParamArr[5], vParamArr[6]);
}

ProxDetectorS(Float:radi, playerid, targetid)
{
	new
		Float: fp_playerPos[3];
	GetPlayerPos(targetid, fp_playerPos[0], fp_playerPos[1], fp_playerPos[2]);
	if(IsPlayerInRangeOfPoint(playerid, radi, fp_playerPos[0], fp_playerPos[1], fp_playerPos[2]) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(targetid))
	{
		return 1;
	}
	return 0;
}

ProxDetector(Float: f_Radius, playerid, string[],col1,col2,col3,col4,col5)
{
	new
		Float: f_playerPos[3];
	GetPlayerPos(playerid, f_playerPos[0], f_playerPos[1], f_playerPos[2]);
	for(new i;i<MAX_PLAYERS;i++)
	{
			if(GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid))
			{
				if(IsPlayerInRangeOfPoint(i, f_Radius / 16, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
					SendClientMessage(i, col1, string);
				}
				else if(IsPlayerInRangeOfPoint(i, f_Radius / 8, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
					SendClientMessage(i, col2, string);
				}
				else if(IsPlayerInRangeOfPoint(i, f_Radius / 4, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
					SendClientMessage(i, col3, string);
				}
				else if(IsPlayerInRangeOfPoint(i, f_Radius / 2, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
					SendClientMessage(i, col4, string);
				}
				else if(IsPlayerInRangeOfPoint(i, f_Radius, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
					SendClientMessage(i, col5, string);
				}
			}
	}
	return 1;
}
ProxDetectorH(Float: f_Radius, playerid, string[],col1,col2,col3,col4,col5)
{
	new
		Float: f_playerPos[3];
	GetPlayerPos(playerid, f_playerPos[0], f_playerPos[1], f_playerPos[2]);
	foreach(Player, i)
	{
		if(GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid))
		{
			if(IsPlayerInRangeOfPoint(i, f_Radius / 16, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
				SendClientMessage(i, col1, string);
			}
			else if(IsPlayerInRangeOfPoint(i, f_Radius / 8, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
				SendClientMessage(i, col2, string);
			}
			else if(IsPlayerInRangeOfPoint(i, f_Radius / 4, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
				SendClientMessage(i, col3, string);
			}
			else if(IsPlayerInRangeOfPoint(i, f_Radius / 2, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
				SendClientMessage(i, col4, string);
			}
			else if(IsPlayerInRangeOfPoint(i, f_Radius, f_playerPos[0], f_playerPos[1], f_playerPos[2])) {
				SendClientMessage(i, col5, "No se entiende lo que dicen, se escucha muy bajo");
			}
		} 
		else SendClientMessage(i, col1, string);
	}
	return 1;
}
stock PlayerPlaySoundEx(soundid, Float:x, Float:y, Float:z) { // Realistic sound playback
	foreach(Player, i) {
		if(IsPlayerInRangeOfPoint(i, 20.0, x, y, z))
			PlayerPlaySound(i, soundid, x, y, z);
	}
	return 1;
}
stock AumetarC()
{
CasasActuales++;
return 1;
}
stock SetPlayerCash(playerid)
{
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid,Info[playerid][pMoney]);
	return 1;
}
stock DarDinero(playerid,money)
{
	Info[playerid][pMoney] = money;
	GivePlayerMoney(playerid,money);
	return 1;
}
stock DarChaleco(playerid,Float:a)
{
	Info[playerid][Chaleco] = a;
    SetPlayerArmour(playerid,a);
	return 1;
}
stock DarVida(playerid,Float:h)
{
	Info[playerid][pVida] = h;
	SetPlayerHealth(playerid,h);
	return 1;
}
timer AntiTrampa[1000](){
	for(new i;i<MAX_PLAYERS;i++)
	{
	    if(IsPlayerConnected(i))
	    {
	        new Float:h,Float:a,M;
	        GetPlayerHealth(i,h);
	        if(h > Info[i][pVida])
			{
 				SetPlayerHealth(i,Info[i][pVida]);
 			}
 			GetPlayerArmour(i,a);
 			if(a > Info[i][Chaleco])
 			{
 			    SetPlayerArmour(i,Info[i][Chaleco]);
	 		}
			M = GetPlayerMoney(i);
			if(M > Info[i][pMoney])
			{
			    SetPlayerCash(i);
			}
		}
	}
	return 1;
}