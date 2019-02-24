enum pCasa
{
	cPro[MAX_PLAYER_NAME],
	cID,
	Float:cx, Float:cy,Float:cz,
	Float:ix,Float:iy,Float:iz,
	cComp,
	cCerradura,
}
new cInfo[MAX_CASAS][pCasa];
new Text3D:CasaLabel[MAX_CASAS], CasasActuales;
new bool:Logueando[MAX_PLAYERS];
new bool:jNuevo[MAX_PLAYERS];
new bool:Muerto[MAX_PLAYERS];
new Hospi[MAX_PLAYERS];
new Vida[MAX_PLAYERS];
new bool:MHospital[MAX_PLAYERS];
new bool:Gritando[MAX_PLAYERS];
new aID[MAX_PLAYERS];
new BanS[250];
new Opcion[MAX_PLAYERS];
/* Payday sistema */
new paydayl;
new levelexp = 4;
new paga[MAX_PLAYERS];
enum cdInfo
{
	cdOwned,
	cdOwner[MAX_PLAYER_NAME],
	Float: cdEntranceX,
	Float: cdEntranceY,
	Float: cdEntranceZ,
	Float: cdExitX,
	Float: cdExitY,
	Float: cdExitZ,
	cdMessage[128],
	cdTill,
	cdInterior,
	Float: cdRadius,
	cdPrice,
	cdPickupID,
	Text3D:cdTextLabel,
	Text3D:cdVehicleLabel[MAX_DEALERSHIPVEHICLES],
	cdVehicleModel[MAX_DEALERSHIPVEHICLES],
	cdVehicleCost[MAX_DEALERSHIPVEHICLES],
	cdVehicleId[MAX_DEALERSHIPVEHICLES],
	Float: cdVehicleSpawnX[MAX_DEALERSHIPVEHICLES],
	Float: cdVehicleSpawnY[MAX_DEALERSHIPVEHICLES],
	Float: cdVehicleSpawnZ[MAX_DEALERSHIPVEHICLES],
	Float: cdVehicleSpawnAngle[MAX_DEALERSHIPVEHICLES],
	Float: cdVehicleSpawn[4],
};
new CDSInfo[MAX_CARDEALERSHIPS][cdInfo];
new carsforplayer[MAX_PLAYERS];
enum pvInfo
{
    Float:pvPosX,
	Float:pvPosY,
	Float:pvPosZ,
 	Float:pvPosAngle,
 	pvVW,
	pvId,
	pvModelId,
	pvLock,
	pvLocked,
	pvPaintJob,
	pvColor1,
	pvColor2,
	pvMods[MAX_MODS],
	pvAllowPlayer[MAX_PLAYER_NAME],
	pvAllowedPlayerId,
	pvPark,
	//pvNumberPlate[32], // sz
	pvPrice,
	pvTicket,
	pvWeapons[3],
	pvWepUpgrade,
	pvImpounded,
	pvFuel,
	Float:pvHealth,
	pvSpawned,
};
new PlayerVehicleInfo[MAX_PLAYERS+1][MAX_PLAYERVEHICLES][pvInfo];
new PlayerCars;
new VehicleFuel[MAX_VEHICLES] = 1000;
new LockStatus[MAX_VEHICLES];
new GiveKeysTo[MAX_PLAYERS];
new Tax = 0;
new VehicleOffer[MAX_PLAYERS];
new VehicleId[MAX_PLAYERS];
new VehiclePrice[MAX_PLAYERS];
new Float: fVehSpeed[MAX_PLAYERS];
/* TextDraw */
new Text:Textdraw0;
new Text:Textdraw1;
new Text:Textdraw2;
new Text:Textdraw3;
new Text:Textdraw4;
new Text:Textdraw5;
new Text:Textdraw6;
new VehicleName[212][] = {
	"Landstalker","Bravura","Buffalo","Linerunner","Perennial","Sentinel","Dumper","Firetruck","Trashmaster","Stretch",
	"Manana","Infernus","Voodoo","Pony","Mule","Cheetah","Ambulance","Leviathan","Moonbeam","Esperanto","Taxi",
	"Washington","Bobcat","Mr Whoopee","BF Injection","Hunter","Premier","Enforcer","Securicar","Banshee","Predator",
	"Bus","Rhino","Barracks","Hotknife","Trailer","Previon","Coach","Cabbie","Stallion","Rumpo","RC Bandit", "Romero",
	"Packer","Monster","Admiral","Squalo","Seasparrow","Pizzaboy","Tram","Trailer","Turismo","Speeder","Reefer","Tropic","Flatbed",
	"Yankee","Caddy","Solair","Berkley's RC Van","Skimmer","PCJ-600","Faggio","Freeway","RC Baron","RC Raider",
	"Glendale","Oceanic","Sanchez","Sparrow","Patriot","Quad","Coastguard","Dinghy","Hermes","Sabre","Rustler",
	"ZR-350","Walton","Regina","Comet","BMX","Burrito","Camper","Marquis","Baggage","Dozer","Maverick","News Chopper",
	"Rancher","FBI Rancher","Virgo","Greenwood","Jetmax","Hotring Racer","Sandking","Blista Compact","Police Maverick",
	"Boxville","Benson","Mesa","RC Goblin","Hotring Racer A","Hotring Racer B","Bloodring Banger","Rancher","Super GT",
	"Elegant","Journey","Bike","Mountain Bike","Beagle","Cropduster","Stuntplane","Tanker","Road Train","Nebula","Majestic",
	"Buccaneer","Shamal","Hydra","FCR-900","NRG-500","HPV-1000","Cement Truck","Tow Truck","Fortune","Cadrona","FBI Truck",
	"Willard","Forklift","Tractor","Combine","Feltzer","Remington","Slamvan","Blade","Freight","Streak","Vortex","Vincent",
	"Bullet","Clover","Sadler","Firetruck","Hustler","Intruder","Primo","Cargobob","Tampa","Sunrise","Merit","Utility",
	"Nevada","Yosemite","Windsor","Monster A","Monster B","Uranus","Jester","Sultan","Stratum","Elegy","Raindance","RC Tiger",
	"Flash","Tahoma","Savanna","Bandito","Freight","Trailer","Kart","Mower","Duneride","Sweeper","Broadway",
	"Tornado","AT-400","DFT-30","Huntley","Stafford","BF-400","Newsvan","Tug","Trailer","Emperor","Wayfarer",
	"Euros","Hotdog","Club","Trailer","Trailer","Andromada","Dodo","RCCam","Launch","Police Car (LSPD)","Police Car (SFPD)",
	"Police Car (LVPD)","Police Ranger","Picador","S.W.A.T. Van","Alpha","Phoenix","Glendale","Sadler","Luggage Trailer A",
	"Luggage Trailer B","Stair Trailer","Boxville","Farm Plow","Utility Trailer"
};