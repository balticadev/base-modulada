/*

	TMK Roleplay v.0.5 | AndresFailout: BASE.
	Todos los créditos correspondientes a Failout por la creación.
	Arreglos por baltica:
	>	Removido pragma tabsize 0, quitadas las warnings.
	>	Modulación en su totalidad a la gamemode (pawno/includes/modulos/...)

*/

// > Includes
#include <a_samp>
#include <zcmd>
#include <streamer>
#include <YSI/y_ini>
#include <djson>
#include <foreach>
#include <sscanf2>
#include <YSI\y_timers>

// > Modulos | baltica
#include <modulos/serverconfig/maximos.inc>
#include <modulos/serverconfig/colores.inc>
#include <modulos/serverconfig/dialogos.inc>
#include <modulos/serverconfig/mapping.inc>
#include <modulos/serverconfig/newyenum.inc>

#pragma unused djson_GameModeExit
#pragma unused djson_GameModeInit

// > Macros
#define funcion%0(%1) forward %0(%1); public %0(%1)
#define loop(%0,%1) for(new %0;%0<%1;%0++)
#define GetVehicleName(%0) 	VehicleName[GetVehicleModel(%0)-400]
#define GetPlayerCash(%0) 	GetPVarInt(%0, "Cash")
#define scripter1 "baltica"
#define Mensaje SendClientMessage
// > Rutas
#define Cuentas "cuenta/%s.ini"
#define DIR_CASAS "Casas/casa%d.ini"

// > Datos del usuario
enum pInfo
{
	pLlave[24],
	Float:pVida,
	Float:Chaleco,
	pSex,
	pFac,
	pRang,
	pTrab,
	Float:px,
	Float:py,
	Float:pz,
	pMoney,
	pBuq,
	pArmas[13],
	pBalas[1],
	pAdmin,
	pAdminEF,
	pAdminES,
	pAdminTech,
	pLlavesDeVeh,
	pVehLlaves,
	pLockCar,
	pLock,
	pVIP,
	pLevel,
	pLevelExp,
	pMuertes,
	pEdad,
	pBan,
	pSkin,
	pLot,
}
new Info[MAX_PLAYERS][pInfo];
/* Main */
main()
{
	print("> Newport Angeles | Dev: "scripter1"\n");
}

// > Modulación
#include <modulos/usuarios/payday.inc>
#include <modulos/serverconfig/mensajes.inc>
#include <modulos/serverconfig/casas.inc>
#include <modulos/serverconfig/funciones.inc>

funcion Cargar_data(playerid,name[],value[])
{
    INI_Int("Contrasena",Info[playerid][pLlave]);
    INI_Float("PosicionX",Info[playerid][px]);
    INI_Float("PosicionY",Info[playerid][py]);
    INI_Float("PosicionZ",Info[playerid][pz]);
    INI_Int("Faccion",Info[playerid][pFac]);
    INI_Int("Rango",Info[playerid][pRang]);
    INI_Int("Ropa",Info[playerid][pSkin]);
    INI_Int("Administracion",Info[playerid][pAdmin]);
    INI_Int("AdminEF",Info[playerid][pAdminEF]);
	INI_Int("AdminES",Info[playerid][pAdminES]);
	INI_Int("AdminTech",Info[playerid][pAdminTech]);
    INI_Int("Loteria",Info[playerid][pLot]);
    INI_Int("Trabajo",Info[playerid][pTrab]);
    INI_Int("Dinero",Info[playerid][pMoney]);
    INI_Int("NivelDeBusqueda",Info[playerid][pBuq]);
   	INI_Int("LlavesDelCoche",Info[playerid][pLlavesDeVeh]);
	INI_Int("LlavesCoche",Info[playerid][pVehLlaves]);
	INI_Int("CocheLock",Info[playerid][pLockCar]);
 	INI_Int("Lock",Info[playerid][pLock]);
 	INI_Int("NivelVip",Info[playerid][pVIP]);
	INI_Int("Nivel",Info[playerid][pLevel]);
	INI_Int("ExperienciaN",Info[playerid][pLevelExp]);
	INI_Int("Muertes",Info[playerid][pMuertes]);
	INI_Int("Edad",Info[playerid][pEdad]);
	INI_Int("Ban",Info[playerid][pBan]);
    for(new v = 0; v < MAX_PLAYERVEHICLES; v++)
    {
        new string[128];
        format(string, 128, "pv%dPosX",v);
        INI_Float(string,PlayerVehicleInfo[playerid][v][pvPosX]);
        format(string, 128, "pv%dPosY",v);
        INI_Float(string,PlayerVehicleInfo[playerid][v][pvPosY]);
        format(string, 128, "pv%dPosZ",v);
        INI_Float(string,PlayerVehicleInfo[playerid][v][pvPosZ]);
        format(string, 128, "pv%dPosAngle",v);
        INI_Float(string,PlayerVehicleInfo[playerid][v][pvPosAngle]);
		format(string, 128, "pv%dVirtualW",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvVW]);
		format(string, 128, "pv%dModelId",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvModelId]);
		format(string, 128, "pv%dLock",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvLock]);
		format(string, 128, "pv%dLocked",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvLocked]);
		format(string, 128, "pv%dPaintJob",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvPaintJob]);
		format(string, 128, "pv%dColor1",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvColor1]);
		format(string, 128, "pv%dColor2",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvColor2]);
		format(string, 128, "pv%dPrice",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvPrice]);
		format(string, 128, "pv%dTicket",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvTicket]);
		format(string, 128, "pv%dWeapon0",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvWeapons][0]);
		format(string, 128, "pv%dWeapon1",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvWeapons][1]);
		format(string, 128, "pv%dWeapon2",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvWeapons][2]);
		format(string, 128, "pv%dWepUpgrade",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvWepUpgrade]);
		format(string, 128, "pv%dFuel",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvFuel]);
		format(string, 128, "pv%dImpound",v);
		INI_Int(string,PlayerVehicleInfo[playerid][v][pvImpounded]);
		format(string, 128, "pv%dHealth",v);
		INI_Float(string,PlayerVehicleInfo[playerid][v][pvHealth]);
		for(new m = 0; m < MAX_MODS; m++)
		{
		    format(string, 128, "pv%dMod%d", v, m);
		    INI_Int(string,PlayerVehicleInfo[playerid][v][pvMods][m]);
		}
    }
	return 1;
}
/* Publics */
public OnGameModeInit()
{
	/* Payday sistema */
    SetTimer("PasarTime", 60000, 1);
	/* Configuracion */
    EnableStuntBonusForAll(0); DisableInteriorEnterExits(); ManualVehicleEngineAndLights(); SetNameTagDrawDistance(30.0); ShowPlayerMarkers(PLAYER_MARKERS_MODE_STREAMED); AllowInteriorWeapons(1); UsePlayerPedAnims();
    SendRconCommand("mapname Los Santos");
	SendRconCommand("weburl Proximamente");
	SendRconCommand("gamemodetext Roleplay Español[RPG]");
	SendRconCommand("hostname Pon tu nombre aca");

	/* Consecionarios */
	LoadcDealerships();
#include <modulos/serverconfig/configconce.inc>
#include <modulos/serverconfig/textdraws.inc>
	Mapeos();
	return 1;
}

public OnGameModeExit()
{
    GCasa();
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	if(Info[playerid][pBan] == 1)
	{
		SetTimerEx("Kickeado",1000,false,"i",playerid);
		SendClientMessage(playerid,Color_Blanco,"Estas Baneado");
	}
	new st[250],Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name));
	if(fexist(UsuCuenta(playerid)))
    {
    	INI_ParseFile(UsuCuenta(playerid), "Cargar_data", .bExtra = true, .extra = playerid);
        ShowPlayerDialog(playerid, Dialogo_Logueo, DIALOG_STYLE_INPUT,"Su cuenta en nuestro panel esta registrada","Por favor Ingrese su Contraseña para Iniciar Secion","Ingresar","Salir");
        Logueando[playerid] = true;
        format(st,sizeof(st),"De nuevo Bienvenido %s[%d]",Name,playerid);
    }
    else
    {
        ShowPlayerDialog(playerid, Dialogo_Registro, DIALOG_STYLE_INPUT,"Su cuenta en nuestro panel no esta registrada","Por favor ingrese una contraseña que desee para iniciar el proceso de registro","Siguiente","Salir");
        format(st,sizeof(st),"Bienvenido %s[%d]",Name,playerid);
        jNuevo[playerid] = true;
    }
    if(IsPlayerNPC(playerid)) {return 0;}
	return 1;
}

public OnPlayerConnect(playerid)
{
	if(PlayerVehicleInfo[playerid][1][pvSpawned] == 0)
    {
	    LoadPlayerVehicles(playerid);
	    GetPlayerVehicleCount(playerid);
	    PlayerVehicleInfo[playerid][1][pvSpawned] = 1;
   	}
   	TextoInicio(playerid);
   	Removes(playerid);
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    Logueando[playerid] = false;
    GuardarCuenta(playerid);
    if(PlayerVehicleInfo[playerid][1][pvSpawned] == 1)
 		{
              UnloadPlayerVehicles(playerid);
              PlayerVehicleInfo[playerid][1][pvSpawned] = 0;
        }
    for(new d = 0 ; d < MAX_PLAYERVEHICLES; d++)
	{
		new Float:x, Float:y, Float:z, Float:angle, Float:health;
		GetVehicleHealth(PlayerVehicleInfo[playerid][d][pvId], health);
		PlayerVehicleInfo[playerid][d][pvHealth] = health;
		if(Info[playerid][pLockCar] == GetPlayerVehicleID(playerid)) Info[playerid][pLockCar] = INVALID_VEHICLE_ID;
		GetVehiclePos(PlayerVehicleInfo[playerid][d][pvId], x, y, z);
		GetVehicleZAngle(PlayerVehicleInfo[playerid][d][pvId], angle);
		UpdatePlayerVehicleParkPosition(playerid, d, x, y, z, angle, health);
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		for(new d = 0 ; d < MAX_PLAYERVEHICLES; d++)
		{
			if(IsPlayerInVehicle(playerid, PlayerVehicleInfo[playerid][d][pvId]))
			{
				new Float:x, Float:y, Float:z, Float:angle, vw;
				vw = GetPlayerVirtualWorld(playerid);
				GetVehiclePos(PlayerVehicleInfo[playerid][d][pvId], x, y, z);
				GetVehicleZAngle(PlayerVehicleInfo[playerid][d][pvId], angle);
				PlayerVehicleInfo[playerid][d][pvPosX] = x;
				PlayerVehicleInfo[playerid][d][pvPosY] = y;
				PlayerVehicleInfo[playerid][d][pvPosZ] = z;
		 		PlayerVehicleInfo[playerid][d][pvPosAngle] = angle;
				PlayerVehicleInfo[playerid][d][pvVW] = vw;
			}
		}
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
	if(Logueando[playerid] == true)
	{
		SetPlayerPos(playerid,Info[playerid][px],Info[playerid][py],Info[playerid][pz]);
		DarDinero(playerid,Info[playerid][pMoney]);
		SetPlayerWantedLevel(playerid,Info[playerid][pBuq]);
		SetPlayerScore(playerid,Info[playerid][pLevel] - Info[playerid][pMuertes]);
	}
	if(jNuevo[playerid] == true)
	{
		SetPlayerPos(playerid,177.0418, 1773.3895, 16.5460);//aca le asignan una posicion para loguear
		switch(Info[playerid][pSex])
		{
		    case 0:
		    {
		        SetPlayerSkin(playerid,29);//Skin hombre
			}
		    case 1:
		    {
				SetPlayerSkin(playerid,64); // Skin Mujer
			}
		}
	}
	ChaoTexto(playerid);
	if(Muerto[playerid] == true) {Muertos(playerid);}
	if(MHospital[playerid] == true)
	{
	SetPlayerPos(playerid,177.0418, 1773.3895, 16.5460);//Aca le asignan coordenadas de spawn luego de salir del hospital
	SetCameraBehindPlayer(playerid);
	DarVida(playerid,100);
	}
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	new Float:X,Float:Y,Float:Z; GetPlayerPos(playerid,X,Y,Z);
    Info[playerid][px] = X; Info[playerid][py] = Y; Info[playerid][pz] = Z; Info[playerid][pMuertes] ++;
	Muerto[playerid] = true;
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
    for(new i = 0;i<MAX_PLAYERS;i++)
	{
	    new v;
	    v = GetPlayerVehicle(i, vehicleid);
	    if (v != -1)
	    {
 			if(PlayerVehicleInfo[i][v][pvId] == vehicleid && GetVehicleModel(vehicleid) != PlayerVehicleInfo[i][v][pvModelId])
	  		{
	   			DestroyVehicle(vehicleid);
				PlayerVehicleInfo[i][v][pvId] = CreateVehicle(PlayerVehicleInfo[i][v][pvModelId], PlayerVehicleInfo[i][v][pvPosX], PlayerVehicleInfo[i][v][pvPosY], PlayerVehicleInfo[i][v][pvPosZ], PlayerVehicleInfo[i][v][pvPosAngle],PlayerVehicleInfo[i][v][pvColor1], PlayerVehicleInfo[i][v][pvColor2], -1);
				if(PlayerVehicleInfo[i][v][pvLocked] == 1) LockPlayerVehicle(i, PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvLock]);
	            ChangeVehiclePaintjob(PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvPaintJob]);
				ChangeVehicleColor(PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvColor1], PlayerVehicleInfo[i][v][pvColor2]);
                SetVehicleVirtualWorld(PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvVW]);
                SetVehicleHealth(PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvHealth]);
				//SetVehicleNumberPlate(PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvNumberPlate]);
				for(new m = 0; m < MAX_MODS; m++)
	   			{
	   			    //if (PlayerVehicleInfo[i][v][pvMods][m] >= 1000 && PlayerVehicleInfo[i][v][pvMods][m] <= 1193)
	   			    //{
		   				//if (InvalidModCheck(GetVehicleModel(vehicleid), PlayerVehicleInfo[i][v][pvMods][m]))
		      			//{
   					AddVehicleComponent(PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvMods][m]);
		      			//}
		      			/*else
		      			{
		      			    printf("Removing invalid mod %d from %d of %s", PlayerVehicleInfo[i][v][pvMods][m], GetVehicleModel(vehicleid), NombreP(i));
		      			    PlayerVehicleInfo[i][v][pvMods][m] = 0;
		      			}*/
					//}
	      		}
 			}
 			else
			{
			    //DestroyVehicle(vehicleid);
			    //PlayerVehicleInfo[i][v][pvId] = CreateVehicle(PlayerVehicleInfo[i][v][pvModelId], PlayerVehicleInfo[i][v][pvPosX], PlayerVehicleInfo[i][v][pvPosY], PlayerVehicleInfo[i][v][pvPosZ], PlayerVehicleInfo[i][v][pvPosAngle],PlayerVehicleInfo[i][v][pvColor1], PlayerVehicleInfo[i][v][pvColor2], -1);
				//if(PlayerVehicleInfo[i][v][pvLocked] == 1) LockPlayerVehicle(i, PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvLock]);
				ChangeVehiclePaintjob(vehicleid, PlayerVehicleInfo[i][v][pvPaintJob]);
				ChangeVehicleColor(vehicleid, PlayerVehicleInfo[i][v][pvColor1], PlayerVehicleInfo[i][v][pvColor2]);
				SetVehicleVirtualWorld(vehicleid, PlayerVehicleInfo[i][v][pvVW]);
				SetVehicleHealth(vehicleid, PlayerVehicleInfo[i][v][pvHealth]);
                //SetVehicleNumberPlate(PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvNumberPlate]);
				for(new m = 0; m < MAX_MODS; m++)
	            {
  	            	AddVehicleComponent(PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvMods][m]);
	            }
				if(PlayerVehicleInfo[i][v][pvLocked] == 1) LockPlayerVehicle(i, PlayerVehicleInfo[i][v][pvId], PlayerVehicleInfo[i][v][pvLock]);
			}
			new string[128];
			format(string,sizeof(string),"Tu %s ha sido enviado a la última posición donde lo aparcaste.",GetVehicleName(vehicleid));
			SendClientMessage(i, Color_Blanco, string);
		}
	}
 	if(LockStatus[vehicleid])
	{
		foreach(Player, i)
		{
			if(Info[i][pLockCar] == vehicleid)
			{
				Info[i][pLockCar] = INVALID_VEHICLE_ID;
			}
		}
	}
	VehicleFuel[vehicleid] = 500;
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	if(Gritando[playerid] == true)
	{
		new string[250],Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name));
		format(string,sizeof(string),"%s [Grita]: %s",Name,text);
		ProxDetectorH(30, playerid, string,ColorH,ColorH2,ColorH3,ColorH4,ColorH5);
		SetPlayerChatBubble(playerid,text,ColorH,30.0,5000);
		return 0;
	}
	else if(Gritando[playerid] == false)
	{
		new string[250],Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name));
		format(string,sizeof(string),"%s Dice: %s",Name,text);
		ProxDetectorH(15, playerid, string,ColorH,ColorH2,ColorH3,ColorH4,ColorH5);
		SetPlayerChatBubble(playerid,text,ColorH,15.0,5000);
		return 0;
	}
	return 0;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
        new engine,lights,alarm,doors,bonnet,boot,objective;
        new newcar = GetPlayerVehicleID(playerid);
        new string[250];
		if(newstate == PLAYER_STATE_DRIVER)
		{
		GetVehicleParamsEx(newcar,engine,lights,alarm,doors,bonnet,boot,objective);
		SetVehicleParamsEx(newcar,engine,lights,alarm,doors,bonnet,boot,objective);
		if(GetCarDealershipVehicleId(newcar) != -1 && GetCarDealershipVehicleId(newcar) == GetPVarInt(playerid, "editingcdveh")) return 1;
        if(GetCarDealershipVehicleId(newcar) != -1)
        {
			format(string, sizeof(string),"¿Quieres comprar este %s?\n\nEste vehiculo tiene el precio de $%d.", GetVehicleName(newcar), CDSInfo[GetCarDealershipId(newcar)][cdVehicleCost][GetCarDealershipVehicleId(newcar)]);
		    ShowPlayerDialog(playerid,DIALOG_CDBUY,DIALOG_STYLE_MSGBOX,"{FFFFFF}Advertencia:",string,"Comprar","Cancelar");
		    TogglePlayerControllable(playerid, false);
		    return 1;
        }
        return 1;
        }
       	for(new i=0;i<MAX_PLAYERS;i++)
		{
      		new v = GetPlayerVehicle(i, newcar);
		    if(v != -1)
			{
				if(i == playerid)
				{
					format(string, sizeof(string),"Eres el dueño de este {FFB400}%s.", GetVehicleName(newcar));
					SendClientMessage(playerid, Color_Blanco, string);
					if(PlayerVehicleInfo[i][v][pvTicket] != 0)
					{
						format(string, sizeof(string),"La policía dejó una multa de $%d en tu vehículo. Usted debe pagar la multa en la central de SFPD.", PlayerVehicleInfo[i][v][pvTicket]);
						SendClientMessage(playerid, Color_Blanco, string);
					}
				}
				else if(i == Info[playerid][pLlavesDeVeh]){
					format(string, sizeof(string),"{FFFFFF}Usted tiene las llaves de este {FFB400}%s {FFFFFF}del dueño {FFB400}%s.", GetVehicleName(newcar), NombreP(i));
					SendClientMessage(playerid, Color_Blanco, string);
				}
				else if(PlayerVehicleInfo[i][v][pvLocked] == 1 && PlayerVehicleInfo[i][v][pvLock] == 1)
				{
				    GetVehicleParamsEx(newcar,engine,lights,alarm,doors,bonnet,boot,objective);
					SetVehicleParamsEx(newcar,engine,lights,VEHICLE_PARAMS_ON,doors,bonnet,boot,objective);
					SetTimerEx("DisableVehicleAlarm", 20000, 0, "d",  newcar);
				}
				else if(PlayerVehicleInfo[i][v][pvLocked] == 1 && PlayerVehicleInfo[i][v][pvLock] == 2)
				{
	          		if(Info[playerid][pAdmin] < 9)
					{
						format(string, sizeof(string), "* %s ha sido sorprendido por la electricidad de la seguridad anti-robo.",NombreP(playerid));
						ProxDetector(30.0, playerid, string, ME_COLOR,ME_COLOR,ME_COLOR,ME_COLOR,ME_COLOR);
						new Float:X, Float:Y, Float:Z, Float:HP;
	     				GetPlayerPos(playerid, X, Y, Z);
	     				PlayerPlaySoundEx(6003, X,Y,Z);
	     				SetPlayerPos(playerid, X + 1, Y + 2, Z);
	         			RemovePlayerFromVehicle(playerid);
	         			SetPVarInt(playerid, "IsFrozen", 1);
	            		TogglePlayerControllable(playerid,0);
		            	SetTimerEx("ReleasePlayer", 10000, 0, "d", playerid);
			            GameTextForPlayer(playerid,"~r~Electricidad!",11000,3);
			            GetPlayerHealth(playerid,HP);
			            DarVida(playerid,HP-15);
					}
				}
				else
				{
	    			format(string, sizeof(string), "{FFFFFF}Advertencia: Este {FFB400}%s {FFFFFF}es de {FFB400}%s.", GetVehicleName(newcar), NombreP(i));
	      			SendClientMessage(playerid, Color_Blanco, string);
				}
				return 1;
			}
		}
		return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	if(GetPlayerVehicle(playerid, vehicleid) > -1)
	{
		PlayerVehicleInfo[playerid][GetPlayerVehicle(playerid, vehicleid)][pvPaintJob] = paintjobid;
	}
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
    if(GetPlayerVehicle(playerid, vehicleid) > -1)
	{
		PlayerVehicleInfo[playerid][GetPlayerVehicle(playerid, vehicleid)][pvColor1] = color1;
		PlayerVehicleInfo[playerid][GetPlayerVehicle(playerid, vehicleid)][pvColor2] = color2;
	}
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}
stock udb_hash(buf[]){ // Dracoblue
    new length=strlen(buf),s1 = 1,s2 = 0,n;
    for (n=0; n<length; n++){
        s1 = (s1 + buf[n]) % 65521,
        s2 = (s2 + s1)     % 65521;
    }
    return (s2 << 16) + s1;
}
funcion RegistrarJugador(playerid,password[])
{
	if(IsPlayerConnected(playerid))
    {
        new INI:File = INI_Open(UsuCuenta(playerid));
        INI_SetTag(File,"datos");
        INI_WriteInt(File,"Contra",udb_hash(password));
        INI_Close(File);
		SetTimerEx("ElecSex",2500,false,"i",playerid);
        GameTextForPlayer(playerid, "~b~Espera un momento se esta creando tu ~r~cuenta", 2500, 3);
       //CrearCuenta(playerid);
    }
	return 1;
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case Dialogo_Registro:
		{
		if(response)
		{
	                if(!strlen(inputtext)) return ShowPlayerDialog(playerid, Dialogo_Registro, DIALOG_STYLE_INPUT, "Fallo en el registro","Por favor ingrese su contraseña nuevamente","Sigueinte","Cancelar");
	                DarDinero(playerid,1000);
	                GetPlayerPos(playerid,Info[playerid][px],Info[playerid][py],Info[playerid][pz]);
					RegistrarJugador(playerid,inputtext);
					ChaoTexto(playerid);
		 }
		 else
		 {
		 	Kick(playerid);
		 }
		}
		case Dialogo_Logueo:
	 	{
	            if ( !response ) return Kick ( playerid );
	            if( response )
	            {
	                if(strcmp(inputtext, Info[playerid][pLlave], true) == 0)
	                {
	                    INI_ParseFile(UsuCuenta(playerid), "Cargar_data", .bExtra = true, .extra = playerid);
	                    IngresarInfo(playerid);
	                    ChaoTexto(playerid);
	                 }
	                else
	                {
	                    ShowPlayerDialog(playerid, Dialogo_Logueo, DIALOG_STYLE_INPUT,"Fallo en el ingreso","Por favor ingrese su contraseña nuevamente","Ingresar","Cancelar");
	                }
	                return 1;
	            }
	  	}
		case Dialogo_Sexo:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0: {SetTimerEx("ElecEdad",2500,false,"i",playerid); Info[playerid][pSex] = 0;}
					case 1: {SetTimerEx("ElecEdad",2500,false,"i",playerid); Info[playerid][pSex] = 1;}
				}
			}
		}
		case D_PASARNIVEL:
		{
		    if(response)
		    {
		        Info[playerid][pLevel] ++;
		        Info[playerid][pLevelExp] = 0;
				SendClientMessage(playerid,Color_Blanco,"Felicidades acabas de subir de nivel");
			}
		}
		case Dialog_dAdmin:
		{
			if(response)
			{
				new id = strval(inputtext);
				if(!IsPlayerConnected(id))return SendClientMessage(playerid,Color_Bot,"ID Invalida");
				aID[id] = id;
				ShowPlayerDialog(playerid,Dialogo_dAdmin2,DIALOG_STYLE_INPUT,"Dar Administrador","Ahora ingresa el nivel administrativo","Aceptar","Salir");
			}
		}
		case Dialogo_Ban:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:{Opcion[playerid] = 1; ShowPlayerDialog(playerid,Dialogo_Ban2,DIALOG_STYLE_INPUT,"Ingresa una ID","Ingresa Una ID para banear","Aceptar","Salir");}
					case 1:{Opcion[playerid] = 2; ShowPlayerDialog(playerid,Dialogo_Ban2,DIALOG_STYLE_INPUT,"Ingresa una ID","Ingresa Una ID para banear","Aceptar","Salir");}
					case 2:{Opcion[playerid] = 3; ShowPlayerDialog(playerid,Dialogo_Ban2,DIALOG_STYLE_INPUT,"Ingresa una ID","Ingresa Una ID para banear","Aceptar","Salir");}
					case 3:{Opcion[playerid] = 4; ShowPlayerDialog(playerid,Dialogo_BanSt,DIALOG_STYLE_INPUT,"Ingresa porque lo banearas","Ingresa la razon del baneo","Aceptar","Salir");}
				}
			}
		}
		case Dialogo_Ban2:
		{
			if(response)
			{
				new id = strval(inputtext);
				new string[250],Name[MAX_PLAYER_NAME],pName[MAX_PLAYER_NAME]; GetPlayerName(playerid,Name,sizeof(Name)); GetPlayerName(id,pName,sizeof(pName));
				switch(Opcion[playerid])
				{
					case 1:
					{
						format(string,sizeof(string),"%s a baneado por ser un niño rata a %s",Name,pName);
						SendClientMessageToAll(Color_Bot,string);
					}
					case 2:
					{
						format(string,sizeof(string),"%s a baneado por Molestar a otros usuarios a %s",Name,pName);
						SendClientMessageToAll(Color_Bot,string);
					}
					case 3:
					{
						format(string,sizeof(string),"%s a baneado por ser un Hacker a %s",Name,pName);
						SendClientMessageToAll(Color_Bot,string);
					}
					case 4:
					{
						format(string,sizeof(string),"%s a baneado por %s a %s",Name,BanS,pName);
						SendClientMessageToAll(Color_Bot,string);
					}
				}
				if(!IsPlayerConnected(id))return SendClientMessage(playerid,Color_Blanco,"ID Invalida");
				Info[id][pBan] = 1;
				SetTimerEx("Kickeado",1000,false,"i",id);
			}
		}
		case Dialogo_BanSt:
		{
			if(response)
			{
				new S = strval(inputtext);
				format(BanS,sizeof(BanS),"%s",S);
				ShowPlayerDialog(playerid,Dialogo_Ban2,DIALOG_STYLE_INPUT,"Ingresa una ID","Ingresa Una ID para banear","Aceptar","Salir");
			}
		}
		case Dialogo_dAdmin2:
		{
			new string[250],Name[MAX_PLAYER_NAME],pName[MAX_PLAYER_NAME],s[250];GetPlayerName(playerid,Name,sizeof(Name));GetPlayerName(aID[playerid],pName,sizeof(pName));
			if(response)
			{
				new n = strval(inputtext);
				switch(n)
				{
					case 1:s = "Ayudante";
					case 2:s = "Super Ayudante";
					case 3:s = "Moderador";
					case 4:s = "Super Moderador";
					case 5:s = "Administrador";
					case 6:s = "Administrador General";
					case 7:s = "Administrador a cargo";
					case 8:s = "Super Administrador";
					case 9:s = "Sub Fundador";
					case 10:s = "Fundador";
					default: return SendClientMessage(playerid,Color_Bot,"ID Invalida");
				}
				Info[aID[playerid]][pAdmin] = n;
				format(string,sizeof(string),"%s le dio a %s el rango de %s",Name,pName,s);
				SendClientMessageToAll(Color_Bot,string);
			}
		}
		case Dialogo_Edad:
		{
			if(response)
			{
				new ed = strval(inputtext);
				if(ed < 0 || ed > 99) return ShowPlayerDialog(playerid,Dialogo_Edad,DIALOG_STYLE_INPUT,"Elige Tu edad","Ingresa tu edad tiene que ser mayor que 0 o menor que 99","Elegir","");
				Info[playerid][pEdad] = ed;
				SetTimerEx("ColocarJ",2500,false,"i",playerid);
			}
		}
	    case DIALOG_CDBUY:
		{
			new string[250];
		    // Account Eating Bug Fix
			if(!IsPlayerInAnyVehicle(playerid))
			{
			    TogglePlayerControllable(playerid, 1);
				SendClientMessage(playerid,Color_Blanco,"Necesitas estar en el vehículo que desea comprar.");
				return 1;
			}

			new vehicleid = GetPlayerVehicleID(playerid);
			new v = GetCarDealershipVehicleId(vehicleid);
			new d = GetCarDealershipId(vehicleid);
			if(response)
			{
			    if(carsforplayer[playerid] == 2) return SendClientMessage(playerid,Color_Blanco,"* Tienes 2 coches liberados, primero guarda uno para comprar otro.");
	            if(CDSInfo[d][cdVehicleSpawn][0] == 0.0 && CDSInfo[d][cdVehicleSpawn][1] == 0.0 && CDSInfo[d][cdVehicleSpawn][2] == 0.0)
	            {
					SendClientMessage(playerid, Color_Blanco, "ERROR: El propietario de este Concesionario no ha configurado completamente los puntos de spawn de coches.");
					RemovePlayerFromVehicle(playerid);
					new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz+1.2);
					TogglePlayerControllable(playerid, 1);
					return 1;
	            }
	            new playervehicleid = GetPlayerFreeVehicleId(playerid);
	            new carsamount = VehicleCount(playerid);
	            if((Info[playerid][pVIP] == 0) && carsamount >= 2)
				{
	                SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, usuarios normales sólo pueden tener 2 coches.");
	                RemovePlayerFromVehicle(playerid);
	                new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz+1.2);
	                TogglePlayerControllable(playerid, 1);
	                return 1;
				}
	            if(Info[playerid][pVIP] == 1 && carsamount >= 4)
	            {
	                SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, BVIP Sólo puede tener 4 coches.");
	                RemovePlayerFromVehicle(playerid);
	                new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz+1.2);
	                TogglePlayerControllable(playerid, 1);
	                return 1;
	            }
	            if(Info[playerid][pVIP] == 2 && carsamount >= 5)
	            {
	                SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, SVIP Sólo puede tener 5 coches.");
	                RemovePlayerFromVehicle(playerid);
	                new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz+1.2);
	                TogglePlayerControllable(playerid, 1);
	                return 1;
	            }
	            if(Info[playerid][pVIP] == 3 && carsamount >= 7)
	            {
	                SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, GVIP Sólo puede tener 7 coches.");
	                RemovePlayerFromVehicle(playerid);
	                new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz+1.2);
	                TogglePlayerControllable(playerid, 1);
	                return 1;
	            }
	            if(Info[playerid][pVIP] == 4 && carsamount >= 8)
	            {
	                SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, PVIP Sólo puede tener 8 coches.");
	                RemovePlayerFromVehicle(playerid);
	                new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz+1.2);
	                TogglePlayerControllable(playerid, 1);
	                return 1;
	            }
			    if(playervehicleid == -1)
			    {
			        SendClientMessage(playerid, Color_Blanco, "ERROR: Este jugador no puede tener más coches.");
	                RemovePlayerFromVehicle(playerid);
	                new Float:slx, Float:sly, Float:slz;
					GetPlayerPos(playerid, slx, sly, slz);
					SetPlayerPos(playerid, slx, sly, slz+1.2);
	                TogglePlayerControllable(playerid, 1);
	                return 1;
			    }
			    new randcolor1 = Random(0, 126);
			    new randcolor2 = Random(0, 126);
			    TogglePlayerControllable(playerid, 1);
			    new cost;
			    if(Info[playerid][pVIP] < 1)
	            {
	                cost = CDSInfo[d][cdVehicleCost][v];
		            if(GetPVarInt(playerid, "Cash") < CDSInfo[d][cdVehicleCost][v])
		            {
						SendClientMessage(playerid, Color_Blanco, "ERROR: No tienes dinero suficiente para comprar este coche.");
						RemovePlayerFromVehicle(playerid);
						new Float:slx, Float:sly, Float:slz;
						GetPlayerPos(playerid, slx, sly, slz);
						SetPlayerPos(playerid, slx, sly, slz+1.2);
						return 1;
		            }
	                format(string, sizeof(string), " Gracias por comprar en %s.", CDSInfo[d][cdMessage]);
			        SendClientMessage(playerid, Color_Blanco, string);
			        SetPVarInt(playerid, "Cash", GetPVarInt(playerid, "Cash")-CDSInfo[d][cdVehicleCost][v]);
			        CDSInfo[d][cdTill] += ( CDSInfo[d][cdVehicleCost][v] * 40 ) / ( 100 );
		        }
		        else
		        {
					cost = ( CDSInfo[d][cdVehicleCost][v] * 80 ) / ( 100 );
		            if(GetPVarInt(playerid, "Cash") < cost)
		            {
						SendClientMessage(playerid, Color_Blanco, "ERROR: No tienes dinero suficiente para comprar este coche.");
						RemovePlayerFromVehicle(playerid);
						new Float:slx, Float:sly, Float:slz;
						GetPlayerPos(playerid, slx, sly, slz);
						SetPlayerPos(playerid, slx, sly, slz+1.2);
						return 1;
		            }

	                format(string, sizeof(string), " Gracias por comprar en %s.", CDSInfo[d][cdMessage]);
			        SendClientMessage(playerid, Color_Blanco, string);
			        SetPVarInt(playerid, "Cash", GetPVarInt(playerid, "Cash") - cost );
					CDSInfo[d][cdTill] += cost;
	     		}
	            CreatePlayerVehicle(playerid, playervehicleid, CDSInfo[d][cdVehicleModel][v], CDSInfo[d][cdVehicleSpawn][0], CDSInfo[d][cdVehicleSpawn][1], CDSInfo[d][cdVehicleSpawn][2], CDSInfo[d][cdVehicleSpawn][3], randcolor1, randcolor2, cost);
	            SetPlayerPos(playerid, CDSInfo[d][cdVehicleSpawn][0], CDSInfo[d][cdVehicleSpawn][1], CDSInfo[d][cdVehicleSpawn][2]+2);
				/*SetTimerEx("PutPlayerInVeh", 2000, 0, "dd", playerid, car);
	            SavecDealership(d);*/
			}
			else
			{
	            RemovePlayerFromVehicle(playerid);
	            new Float:slx, Float:sly, Float:slz;
				GetPlayerPos(playerid, slx, sly, slz);
				SetPlayerPos(playerid, slx, sly, slz+1.2);
	            TogglePlayerControllable(playerid, 1);
				return 1;
			}
		}
		case DIALOG_CDEDIT:
		{ // Concesionario dialog
			new string[250];
			if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
	            if(listitem == 0) // New Vehicle
				{
					format(string, sizeof(string),"Por favor, escriba la identificación del modelo del nuevo vehículo.");
			        ShowPlayerDialog(playerid,DIALOG_CDNEWVEH,DIALOG_STYLE_INPUT,"Advertencia:",string,"Ok","Cancelar");
				}
				else if(listitem == 1) // My Vehicles
				{
					new vehicles;
	                for(new i=0; i<MAX_DEALERSHIPVEHICLES; i++)
		            {
						if(CDSInfo[GetPVarInt(playerid, "editingcd")][cdVehicleModel][i] != 0)
						{
							vehicles++;
			                format(string, sizeof(string), "Vehiculo %d| Nombre: %s | Precio: %d.",i+1,GetVehicleName(CDSInfo[GetPVarInt(playerid, "editingcd")][cdVehicleId][i]),CDSInfo[GetPVarInt(playerid, "editingcd")][cdVehicleCost][i]);
			                SendClientMessage(playerid, Color_Blanco, string);
						}
					}
					if(vehicles)
					{
					    ShowPlayerDialog(playerid, DIALOG_CDEDITCARS, DIALOG_STYLE_INPUT, "Concesionario:", " Elija un vehículo para editar:", "Editar", "Atrás");
					}
					else
					{
						SendClientMessage(playerid, Color_Blanco, " Este Concesionario no tiene ningún coche.");
					}
				}
				else if(listitem == 2) // Upgrade
				{
					new listitems[] = "1 Vehicle Spawn\n2 Radio\n3 Nombre del Negocio";
				    ShowPlayerDialog(playerid,DIALOG_CDUPGRADE,DIALOG_STYLE_LIST,"Elige y continua.", listitems,"Ok","Cancelar");
				}
				else if(listitem == 3) // Till
				{
					new listitems[] = "1 Retirar\n2 Depositar";
				    ShowPlayerDialog(playerid,DIALOG_CDTILL,DIALOG_STYLE_LIST,"Elige y continua.", listitems,"Ok","Cancelar");
				}
			}
			else
			{
				SavecDealership(GetPVarInt(playerid, "editingcd"));
	            SetPVarInt(playerid, "editingcd", -1);
			}
		}
		case DIALOG_CDTILL:
		{ // Concesionario dialog
			new string[250];
		    if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
	            if(listitem == 0) // Withdraw
				{
					format(string, sizeof(string), "Tienes $%d en la cuenta de tu caja.\n\n\tCuanto deseas retirar?", CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill]);
					ShowPlayerDialog(playerid,DIALOG_CDWITHDRAW,DIALOG_STYLE_INPUT,"Retirar", string,"Ok","Cancelar");
				}
				else if(listitem == 1) // Deposit
				{
					format(string, sizeof(string), "Tienes $%d en la cuenta de tu caja.\n\n\tCuanto deseas depositar?", CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill]);
					ShowPlayerDialog(playerid,DIALOG_CDDEPOSIT,DIALOG_STYLE_INPUT,"Depositar", string,"Ok","Cancelar");
				}
			}
			else
			{
	            SavecDealership(GetPVarInt(playerid, "editingcd"));
	            SetPVarInt(playerid, "editingcd", -1);
			}
		}
		case DIALOG_CDWITHDRAW:
		{ // Concesionario dialog
			new string[250];
			if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
			    if (isnumeric(inputtext))
		        {
		             new money = strval(inputtext);
		             if(CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill] < money)
		             {
	                     format(string, sizeof(string), "No tienes ese dinero en tu caja!\n\nTienes $%d en tu caja.\n\n\tCuanto dinero quieres retirar?", CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill]);
					     ShowPlayerDialog(playerid,DIALOG_CDWITHDRAW,DIALOG_STYLE_INPUT,"Retirar", string,"Ok","Cancelar");
	                     return 1;
		             }
		             CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill] -= money;
		             SetPVarInt(playerid, "Cash", GetPVarInt(playerid, "Cash")+money);
		             format(string, sizeof(string), "Retiraste $%d de tu caja, nuevo balance: $%d", money, CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill]);
		             SendClientMessage(playerid, Color_Blanco, string);
		             SavecDealership(GetPVarInt(playerid, "editingcd"));
	                 SetPVarInt(playerid, "editingcd", -1);
				}
	        }
			else
			{
	             SavecDealership(GetPVarInt(playerid, "editingcd"));
	             SetPVarInt(playerid, "editingcd", -1);
			}
		}
		case DIALOG_CDSELL:
		{
			new string[250];
			if(response)
			{
				if(GetPVarInt(playerid, "editingcd") == -1) return 1;
	            SetPVarInt(playerid, "Cash", GetPVarInt(playerid, "Cash")+ (CDSInfo[GetPVarInt(playerid, "editingcd")][cdPrice] / 2));
				SellCarDealership(GetPVarInt(playerid, "editingcd"));
				format(string, sizeof(string), "Concesionario de coches vendido con éxito por %d.", CDSInfo[GetPVarInt(playerid, "editingcd")][cdPrice] / 2);
				SendClientMessage(playerid, Color_Blanco, string);
			}
			else
			{
	            SetPVarInt(playerid, "editingcd", -1);
				return 1;
			}
		}
		case DIALOG_CDDEPOSIT:
		{ // Concesionario dialog
			new string[250];
			if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
			    if (isnumeric(inputtext))
		        {
		             new money = strval(inputtext);
		             if(GetPVarInt(playerid, "Cash") < money)
		             {
	                     format(string, sizeof(string), "No tienes el dinero especificado!\n\nTienes $%d en tu caja.\n\n\tCuanto dinero quieres depositar?", CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill]);
					     ShowPlayerDialog(playerid,DIALOG_CDDEPOSIT,DIALOG_STYLE_INPUT,"Deposit", string,"Select","Cancel");
	                     return 1;
		             }
		             CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill] += money;
		             SetPVarInt(playerid, "Cash", GetPVarInt(playerid, "Cash")-money);
		             format(string, sizeof(string), "Depositaste $%d a tu caja, Nuevo Balance: $%d", money, CDSInfo[GetPVarInt(playerid, "editingcd")][cdTill]);
		             SendClientMessage(playerid, Color_Blanco, string);
		             SavecDealership(GetPVarInt(playerid, "editingcd"));
	                 SetPVarInt(playerid, "editingcd", -1);
				}
			}
			else
			{
	             SavecDealership(GetPVarInt(playerid, "editingcd"));
	             SetPVarInt(playerid, "editingcd", -1);
			}
		}
		case DIALOG_CDNEWVEH:
		{ // Concesionario dialog
			if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
				new modelid, d;
				new Float: x, Float: y, Float: z, Float: a;
				new text_info[128];
				d = GetPVarInt(playerid, "editingcd");
				GetPlayerPos(playerid,x,y,z);
		        GetPlayerFacingAngle(playerid, a);
		        if (!isnumeric(inputtext)) return SendClientMessage(playerid, Color_Blanco, "ERROR: El modelo debe ser números.");
	            if (IsPlayerInRangeOfPoint(playerid, CDSInfo[d][cdRadius], CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]))
		        {
		             modelid = strval(inputtext);
		             if(modelid < 400 || modelid > 611) { SendClientMessage(playerid, Color_Blanco, "   ID´s: No menor de 400 y no mayor de 611 !"); return 1; }
		             new cdvehicleid = CreateCarDealershipVehicle(d, modelid, x, y, z, a, 1337);
		             if(cdvehicleid == -1)
			         {
			             SendClientMessage(playerid, Color_Blanco, "ERROR: El coche no se puede crear.");
			         }
		             else
		             {
						 PutPlayerInVehicle(playerid, CDSInfo[d][cdVehicleId][cdvehicleid], 0);
	                     format(text_info, sizeof(text_info), " Vehículo de Concesionario creado con la ID %d.", cdvehicleid-1);
			             SendClientMessage(playerid, Color_Blanco, text_info);
			             SendClientMessage(playerid, Color_Blanco, " Por favor, ponte donde quieres añadir tu nuevo vehículo.");
					     SendClientMessage(playerid, Color_Blanco, " Una vez listo, presiona el botón FIRE - DISPARAR (CLICK).");
					     SetPVarInt(playerid, "editingcdvehnew", 1);
			             SetPVarInt(playerid, "editingcdveh", cdvehicleid);
		             }
		        }
		        else
		        {
	                 SendClientMessage(playerid, Color_Blanco, "ERROR: Estas fuera del radio del Concesionario, por favor vuelve a intentarlo.");
	                 TogglePlayerControllable(playerid, true);
		        }
			}
			else
			{
	            TogglePlayerControllable(playerid, true);
				SetPVarInt(playerid, "editingcd", -1);
			}
		}
		case DIALOG_CDEDITCARS:
		{ // Concesionario dialog
			if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
				new cdvid;
	            if (isnumeric(inputtext))
		        {
		             cdvid = strval(inputtext);
		             if(CDSInfo[GetPVarInt(playerid, "editingcd")][cdVehicleModel][cdvid-1])
		             {
		                 SetPVarInt(playerid, "editingcdveh", cdvid-1);
		                 new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Vehiculo";
				         ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
					 }
		        }
			}
			else
			{
			    new listitems[] = "1 Nuevo Coche\n2 Mis Coches\n3 Mejorar\n4 Ganancias";
				ShowPlayerDialog(playerid,DIALOG_CDEDIT,DIALOG_STYLE_LIST,"Elige y Continua", listitems,"Ok","Cancelar");
			}
		}
		case DIALOG_CDUPGRADE:
		{ // Concesionario dialog
			if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
	            if(listitem == 0) // Vehicle Spawn
				{
			        SendClientMessage(playerid, Color_Blanco, " Por favor, ponte donde quieres que este el vehiculo para la venta.");
					SendClientMessage(playerid, Color_Blanco, " Una vez listo, presiona el botón FIRE - DISPARAR (CLICK).");
					SetPVarInt(playerid, "editingcdvehpos", 2);
				}
	            if(listitem == 1) // Radius
				{
					ShowPlayerDialog(playerid, DIALOG_CDRADIUS, DIALOG_STYLE_INPUT, "Concesionario:", " Elige el nuevo Radio:", "Editar", "Atrás");
				}
				else if(listitem == 2) // Dealership Name
				{
					ShowPlayerDialog(playerid, DIALOG_CDNAME, DIALOG_STYLE_INPUT, "Concesionario:", " Elige el nuevo Nombre:", "Editar", "Atrás");
				}
				/*else if(listitem == 3) // Price
				{
					ShowPlayerDialog(playerid, DIALOG_CDPRICE, DIALOG_STYLE_INPUT, "Concesionario:", " Elige el nuevo precio:", "Editar", "Atrás");
				}*/
			}
			else
			{
	            SavecDealership(GetPVarInt(playerid, "editingcd"));
	            SetPVarInt(playerid, "editingcd", -1);
			}
		}
		case DIALOG_CDEDITONE:
		{ // Concesionario dialog
			new string[250];
			if(response && GetPVarInt(playerid, "editingcd") != -1 && GetPVarInt(playerid, "editingcdveh") != -1)
			{
	            if(listitem == 0) // Edit Model
				{
		             ShowPlayerDialog(playerid, DIALOG_CDEDITMODEL, DIALOG_STYLE_INPUT, "Concesionario:", " * Elige el nuevo modelo (id):", "Editar", "Atrás");
		        }
		        else if(listitem == 1) // Edit Cost
				{
		             ShowPlayerDialog(playerid, DIALOG_CDEDITCOST, DIALOG_STYLE_INPUT, "Concesionario:",  " * Elige el nuevo precio del coche:", "Editar", "Atrás");
		        }
		        else if(listitem == 2) // Edit Park
				{
					 PutPlayerInVehicle(playerid, CDSInfo[GetPVarInt(playerid, "editingcd")][cdVehicleId][GetPVarInt(playerid, "editingcdveh")], 0);
		             SendClientMessage(playerid, Color_Blanco, " Por favor, ponte donde quieres aparcar el vehículo.");
					 SendClientMessage(playerid, Color_Blanco, " Una vez listo, presiona el botón FIRE - DISPARAR (CLICK).");
					 SetPVarInt(playerid, "editingcdvehpos", 1);
		        }
		        else if(listitem == 3) // Delete Vehicle
				{
		             format(string, sizeof(string), "¿Seguro que quieres eliminar este %s?\nNota: No recibirás ningún tipo de dinero.",
					 GetVehicleName(CDSInfo[GetPVarInt(playerid, "editingcd")][cdVehicleId][GetPVarInt(playerid, "editingcdveh")]));
			         ShowPlayerDialog(playerid,DIALOG_CDDELVEH,DIALOG_STYLE_MSGBOX,"Advertencia:",string,"Ok","Cancel");
		        }
			}
			else
			{
	            SavecDealership(GetPVarInt(playerid, "editingcd"));
	            SetPVarInt(playerid, "editingcdveh", -1);
			}
		}
		case DIALOG_CDRADIUS:
		{ // Concesionario dialog
			new string [250];
			if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
				new d;
				d = GetPVarInt(playerid, "editingcd");
				new Float:radius = floatstr(inputtext);
				new Float:radiusex = CDSInfo[d][cdRadius];
				new test = floatround(radius), test1 = floatround(radiusex);
	            if (CDSInfo[d][cdRadius] > radius)
		        {
					 new cost = ( test - test1 ) * ( test1 * 1000 );
					 if(GetPVarInt(playerid, "Cash") < cost)
					 {
	                     format(string, sizeof(string), "ERROR: No tienes suficiente dinero de esta mejora ($%d).",cost);
	                     SendClientMessage(playerid, Color_Blanco, string);
	                     return 1;
					 }
					 format(string, sizeof(string), " Concesionario: Radio actualizado desde %.1f a %.1f por $%d.",radiusex, radius, cost);
	                 SendClientMessage(playerid, Color_Blanco, string);
		             CDSInfo[d][cdRadius] = radius;
	        		 format(string, sizeof(string),"Concesionario (%d) %s\nDueño: %s", d, CDSInfo[d][cdMessage], CDSInfo[d][cdOwner]);
		             UpdateDynamic3DTextLabelText(CDSInfo[d][cdTextLabel], Color_Azul, string);
		             new listitems[] = "1 Spawn de Vehiculo\n2 Radio\n3 Nombre del Concesionario\n4 Precio";
				     ShowPlayerDialog(playerid,DIALOG_CDUPGRADE,DIALOG_STYLE_LIST,"Elige y continúa", listitems,"Ok","Cancelar");
				     SavecDealership(GetPVarInt(playerid, "editingcd"));
		        }
			}
			else
			{
			    new listitems[] = "1 Spawn de Vehiculo\n2 Radio\n3 Nombre del Concesionario";
				ShowPlayerDialog(playerid,DIALOG_CDUPGRADE,DIALOG_STYLE_LIST,"Elige y continúa", listitems,"Ok","Cancelar");
			}
		}
		case DIALOG_CDNAME:
		{ // Concesionario dialog
			new string[250];
			if(response && GetPVarInt(playerid, "editingcd") != -1)
			{
				new d;
				d = GetPVarInt(playerid, "editingcd");
	            if (!strlen(inputtext))
				{
				    SendClientMessage(playerid, Color_Azul, "** Debes escribir un nombre **");
	    	        ShowPlayerDialog(playerid, DIALOG_CDNAME, DIALOG_STYLE_INPUT, "Concesionario:", " Elige el nuevo nombre:", "Editar", "Atrás");
			        return 1;
				}
				new cost = strlen(inputtext) * 50;
				format(string, sizeof(string), " Nombre del Concesionario fue mejorado de %s a %s por $%d.", CDSInfo[d][cdMessage], inputtext, cost);
	            SendClientMessage(playerid, Color_Blanco, string);
		        strmid(CDSInfo[d][cdMessage], inputtext, 0, strlen(inputtext), 255);
		        format(string, 128,"Concesionario (%d) %s\nDueño: %s", d, CDSInfo[d][cdMessage], CDSInfo[d][cdOwner]);
		        UpdateDynamic3DTextLabelText(CDSInfo[d][cdTextLabel], Color_Azul, string);
		        new listitems[] = "1 Spawn de Vehiculo\n2 Radio\n3 Nombre del Concesionario";
				ShowPlayerDialog(playerid,DIALOG_CDUPGRADE,DIALOG_STYLE_LIST,"Elige y continúa", listitems,"Ok","Cancelar");
				SavecDealership(GetPVarInt(playerid, "editingcd"));
			}
			else
			{
			    new listitems[] = "1 Spawn de Vehiculo\n2 Radio\n3 Nombre del Concesionario";
				ShowPlayerDialog(playerid,DIALOG_CDUPGRADE,DIALOG_STYLE_LIST,"Elige y continúa", listitems,"Ok","Cancelar");
			}
		}
		case DIALOG_CDEDITPARK:
		{ // Concesionario dialog
			if(response && GetPVarInt(playerid, "editingcd") != -1 && GetPVarInt(playerid, "editingcdveh") != -1 &&  GetPVarInt(playerid, "editingcdvehpos") == 1 || GetPVarInt(playerid, "editingcdvehnew"))
			{
				new Float: x, Float: y, Float: z, Float: a;
				new d, v, text_info[128];
				d = GetPVarInt(playerid, "editingcd");
				v = GetPVarInt(playerid, "editingcdveh");
				GetVehiclePos(CDSInfo[d][cdVehicleId][v], x, y, z);
		        GetVehicleZAngle(CDSInfo[d][cdVehicleId][v], a);
				if(IsPlayerInRangeOfPoint(playerid, CDSInfo[d][cdRadius], CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]))
			    {
				     CDSInfo[d][cdVehicleSpawnX][v] = x;
	                 CDSInfo[d][cdVehicleSpawnY][v] = y;
	                 CDSInfo[d][cdVehicleSpawnZ][v] = z;
	                 CDSInfo[d][cdVehicleSpawnAngle][v] = a;
	                 SetPVarInt(playerid, "editingcdvehpos", 0);
	                 SetPVarInt(playerid, "editingcdvehnew", 0);
	                 DestroyDynamic3DTextLabel(CDSInfo[d][cdVehicleLabel][v]);
		             DestroyVehicle(CDSInfo[d][cdVehicleId][v]);
		             new carcreated;
		             carcreated = CreateVehicle(CDSInfo[d][cdVehicleModel][v], CDSInfo[d][cdVehicleSpawnX][v], CDSInfo[d][cdVehicleSpawnY][v], CDSInfo[d][cdVehicleSpawnZ][v], CDSInfo[d][cdVehicleSpawnAngle][v], 0, 0, 6);
			         format(text_info, sizeof(text_info), "%s En Venta | Precio: %d", GetVehicleName(carcreated), CDSInfo[d][cdVehicleCost][v]);
	                 CDSInfo[d][cdVehicleLabel][v] = CreateDynamic3DTextLabel(text_info,Color_Blanco,0.0, 0.0, 0.0,8.0,INVALID_PLAYER_ID,carcreated);
		             CDSInfo[d][cdVehicleId][v] = carcreated;
		             TogglePlayerControllable(playerid, true);
		             new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Vehiculo";
				     ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
				     SavecDealership(d);
				}
				else
				{
	                 SendClientMessage(playerid, Color_Blanco, "ERROR: Estás fuera del radio de este Concesionario, por favor vuelve a intentarlo.");
	                 TogglePlayerControllable(playerid, true);
				}
			}
			else if(response && GetPVarInt(playerid, "editingcd") != -1 && GetPVarInt(playerid, "editingcdvehpos") == 2)
			{
				new Float: x, Float: y, Float: z, Float: a;
				new d;
				GetPlayerPos(playerid,x,y,z);
		        GetPlayerFacingAngle(playerid, a);
				d = GetPVarInt(playerid, "editingcd");
				if(IsPlayerInRangeOfPoint(playerid, CDSInfo[d][cdRadius], CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]))
			    {
				     CDSInfo[d][cdVehicleSpawn][0] = x;
	                 CDSInfo[d][cdVehicleSpawn][1] = y;
	                 CDSInfo[d][cdVehicleSpawn][2] = z;
	                 CDSInfo[d][cdVehicleSpawn][3] = a;
	                 SetPVarInt(playerid, "editingcdvehpos", 0);
		             TogglePlayerControllable(playerid, true);
		             new listitems[] = "1 Spawn de Vehiculo\n2 Radio\n3 Nombre del Concesionario";
				     ShowPlayerDialog(playerid,DIALOG_CDUPGRADE,DIALOG_STYLE_LIST,"Elige para continuar", listitems,"Ok","Cancelar");
				     SavecDealership(d);
				}
				else
				{
	                 SendClientMessage(playerid, Color_Blanco, "ERROR: Estás fuera del radio de este Concesionario, por favor vuelve a intentarlo.");
	                 TogglePlayerControllable(playerid, true);
				}
			}
			else if(!response && GetPVarInt(playerid, "editingcd") != -1 && GetPVarInt(playerid, "editingcdvehpos") == 1)
			{
	            new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Vehiculo";
				ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
				TogglePlayerControllable(playerid, true);
				SetPVarInt(playerid, "editingcdvehpos", 0);
			}
			else if(!response && GetPVarInt(playerid, "editingcd") != -1 && GetPVarInt(playerid, "editingcdvehpos") == 2)
			{
	            new listitems[] = "1 Spawn de Vehiculo\n2 Radio\n3 Nombre del Concesionario";
			    ShowPlayerDialog(playerid,DIALOG_CDUPGRADE,DIALOG_STYLE_LIST,"Elige para continuar", listitems,"Ok","Cancelar");
				TogglePlayerControllable(playerid, true);
				SetPVarInt(playerid, "editingcdvehpos", 0);
			}
		}
	   case DIALOG_CDEDITMODEL:
		{ // Concesionario dialog
			if(response && GetPVarInt(playerid, "editingcd") != -1 && GetPVarInt(playerid, "editingcdveh") != -1)
			{
				new modelid, d, v;
				new text_info[128];
				d = GetPVarInt(playerid, "editingcd");
				v = GetPVarInt(playerid, "editingcdveh");
	            if (isnumeric(inputtext))
		        {
		             modelid = strval(inputtext);
		             if(modelid < 400 || modelid > 611) { SendClientMessage(playerid, Color_Blanco, "   ID´s: No puede ser menos de 400 o mayor 611 !"); return 1; }
		             CDSInfo[d][cdVehicleModel][v] = modelid;
		             DestroyDynamic3DTextLabel(CDSInfo[d][cdVehicleLabel][v]);
		             DestroyVehicle(CDSInfo[d][cdVehicleId][v]);
		             new carcreated;
		             carcreated = CreateVehicle(CDSInfo[d][cdVehicleModel][v], CDSInfo[d][cdVehicleSpawnX][v], CDSInfo[d][cdVehicleSpawnY][v], CDSInfo[d][cdVehicleSpawnZ][v], CDSInfo[d][cdVehicleSpawnAngle][v], 0, 0, 6);
			         format(text_info, sizeof(text_info),"%s En Venta | Precio: %d", GetVehicleName(carcreated), CDSInfo[d][cdVehicleCost][v]);
	                 CDSInfo[d][cdVehicleLabel][v] = CreateDynamic3DTextLabel(text_info,Color_Blanco,0.0, 0.0, 0.0,8.0,INVALID_PLAYER_ID,carcreated);
		             CDSInfo[d][cdVehicleId][v] = carcreated;
		             new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Vehiculo";
				     ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
				     SavecDealership(d);
		        }
			}
			else
			{
			    new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Vehiculo";
				ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
			}
		}
		case DIALOG_CDEDITCOST:
		{ // Concesionario dialog
			if(response && GetPVarInt(playerid, "editingcd") != -1 && GetPVarInt(playerid, "editingcdveh") != -1)
			{
				new price, d, v;
				new text_info[128];
				d = GetPVarInt(playerid, "editingcd");
				v = GetPVarInt(playerid, "editingcdveh");
	            if (isnumeric(inputtext))
		        {
		             price = strval(inputtext);
		             CDSInfo[d][cdVehicleCost][v] = price;
		             format(text_info, sizeof(text_info), "%s En Venta | Precio: %d", GetVehicleName(CDSInfo[d][cdVehicleId][v]), CDSInfo[d][cdVehicleCost][v]);
		             UpdateDynamic3DTextLabelText(CDSInfo[d][cdVehicleLabel][v], Color_Blanco, text_info);
		             new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Vehiculo";
				     ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
				     SavecDealership(d);
		        }
			}
			else
			{
			    new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Vehiculo";
				ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
			}
		}
		case DIALOG_CDDELVEH:
		{ // Concesionario dialog
			if(response && GetPVarInt(playerid, "editingcd") != -1 && GetPVarInt(playerid, "editingcdveh") != -1)
			{
				DestroyCarDealershipVehicle(GetPVarInt(playerid, "editingcd"), GetPVarInt(playerid, "editingcdveh"));
				SavecDealership(GetPVarInt(playerid, "editingcd"));
			}
			else
			{
	  			new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Vehiculo";
				ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
			}
		}
		case MPSPAYTICKETS:
		{
		    if(response)
		    {
				new
					szMessage[128];

				if(Info[playerid][pBuq] != 0)
				{
					format(szMessage, sizeof(szMessage), "%s intenta pagar multas y es buscado por la policía - Nivel de búsqueda: %i.", NombreP(playerid), Info[playerid][pBuq]);
					SendRadioMessage(1, TEAM_RADIO_COLOR, szMessage);
					SendRadioMessage(2, TEAM_RADIO_COLOR, szMessage);
					return SendClientMessage(playerid, Color_Azul, "La policía ha dado comunicado que usted está buscado, y están en camino.");
				}
				if(PlayerVehicleInfo[playerid][listitem][pvTicket])
				{
					if(GetPlayerCash(playerid) < PlayerVehicleInfo[playerid][listitem][pvTicket])
					{
						return SendClientMessage(playerid, Color_Blanco, "No tienes suficiente dinero para pagar la multa.");
					}
					DarDinero(playerid, -PlayerVehicleInfo[playerid][listitem][pvTicket]);
					Tax += PlayerVehicleInfo[playerid][listitem][pvTicket];
					format(szMessage, sizeof(szMessage), "Pagaste la multa de $%d de tu %s.", PlayerVehicleInfo[playerid][listitem][pvTicket], VehicleName[PlayerVehicleInfo[playerid][listitem][pvModelId] - 400]);
					SendClientMessage(playerid, Color_Blanco, szMessage);
					PlayerVehicleInfo[playerid][listitem][pvTicket] = 0;
				}
				else if(PlayerVehicleInfo[playerid][listitem][pvImpounded])
				{

					new
						iCost = (PlayerVehicleInfo[playerid][listitem][pvPrice] / 20) + PlayerVehicleInfo[playerid][listitem][pvTicket] + (Info[playerid][pLevel] * 2);

					if(GetPlayerCash(playerid) < iCost)
					{
						return SendClientMessage(playerid, Color_Blanco, "No tienes suficiente dinero para pagar la multa.");
					}

					format(szMessage, sizeof(szMessage), "Liberaste tu %s por $%i.", VehicleName[PlayerVehicleInfo[playerid][listitem][pvModelId] - 400], iCost);
					SendClientMessage(playerid, Color_Azul, szMessage);
					SendClientMessage(playerid, Color_Blanco, "Tu auto se encuentra en el depósito municipal, puedes abrir la reja usando /deposito.");
					DarDinero(playerid, -iCost);
					Tax += iCost;
					PlayerVehicleInfo[playerid][listitem][pvImpounded] = 0;
					PlayerVehicleInfo[playerid][listitem][pvPosX] = 1655.4379;
					PlayerVehicleInfo[playerid][listitem][pvPosY] = -1829.5668;
					PlayerVehicleInfo[playerid][listitem][pvPosZ] = 13.2677;
					PlayerVehicleInfo[playerid][listitem][pvPosAngle] = 91.6165;
					PlayerVehicleInfo[playerid][listitem][pvTicket] = 0;
					PlayerVehicleInfo[playerid][listitem][pvVW] = 0;
	                ++PlayerCars;
					PlayerVehicleInfo[playerid][listitem][pvId] = CreateVehicle(PlayerVehicleInfo[playerid][listitem][pvModelId], PlayerVehicleInfo[playerid][listitem][pvPosX], PlayerVehicleInfo[playerid][listitem][pvPosY], PlayerVehicleInfo[playerid][listitem][pvPosZ], PlayerVehicleInfo[playerid][listitem][pvPosAngle],PlayerVehicleInfo[playerid][listitem][pvColor1], PlayerVehicleInfo[playerid][listitem][pvColor2], -1);
					SetPlayerVirtualWorld(PlayerVehicleInfo[playerid][listitem][pvId], PlayerVehicleInfo[playerid][listitem][pvVW]);
					VehicleFuel[PlayerVehicleInfo[playerid][listitem][pvId]] = PlayerVehicleInfo[playerid][listitem][pvFuel];
					if(PlayerVehicleInfo[playerid][listitem][pvLocked] == 1) LockPlayerVehicle(playerid, PlayerVehicleInfo[playerid][listitem][pvId], PlayerVehicleInfo[playerid][listitem][pvLock]);
					LoadPlayerVehicleMods(playerid, listitem);
				}
				else SendClientMessage(playerid, Color_Blanco, "Este coche, o bien no existe, o no es necesario liberar o tiene sus multas pagadas.");
		    }
			return 1;
		}
				case GIVEKEYS:
			{
				new string[250];
			    if(response)
			    {
					if(PlayerVehicleInfo[playerid][listitem][pvId] == INVALID_PLAYER_VEHICLE_ID)
					{
			            SendClientMessage(playerid, Color_Blanco, "No se puede dar las llaves de un vehículo que no existe o que está embargado.");
			            GiveKeysTo[playerid] = INVALID_PLAYER_ID;
			            return 1;
					}
			        if(PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId] != INVALID_PLAYER_ID)
			        {
			            SendClientMessage(playerid, Color_Blanco, "Usted ya ha dado a alguien las llaves de este coche.");
			            GiveKeysTo[playerid] = INVALID_PLAYER_ID;
			            return 1;
			        }
			        if(Info[GiveKeysTo[playerid]][pLlavesDeVeh] != INVALID_PLAYER_ID)
			        {
			            SendClientMessage(playerid, Color_Blanco, "Ese jugador ya tiene las llaves de un coche distinto.");
			            GiveKeysTo[playerid] = INVALID_PLAYER_ID;
			            return 1;
			        }
					PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId] = GiveKeysTo[playerid];
					Info[GiveKeysTo[playerid]][pVehLlaves] = listitem;
					Info[GiveKeysTo[playerid]][pLlavesDeVeh] = playerid;
					format(string, sizeof(string), "%s te ha dado las llaves de su %s.", NombreP(playerid), GetVehicleName(PlayerVehicleInfo[playerid][listitem][pvId]));
					SendClientMessage(GiveKeysTo[playerid], Color_Blanco, string);
					format(string, sizeof(string), "Has dado a %s las llaves de tu %s.", NombreP(GiveKeysTo[playerid]), GetVehicleName(PlayerVehicleInfo[playerid][listitem][pvId]));
					SendClientMessage(playerid, Color_Blanco, string);
					GiveKeysTo[playerid] = INVALID_PLAYER_ID;
			    }
			}
			case REMOVEKEYS:
			{
				new string[250];
			    if(response)
			    {
			        if(PlayerVehicleInfo[playerid][listitem][pvId] == INVALID_PLAYER_VEHICLE_ID) {
			            SendClientMessage(playerid, Color_Blanco, "No se puede quitar las llaves de un vehículo que no existe o que estánembargados.");
			            return 1;
					}
			        if(PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId] != PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId])
			        {
			            SendClientMessage(playerid, Color_Blanco, "Este jugador no tiene las llaves de este coche.");
			            return 1;
			        }
			        if(PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId] == INVALID_PLAYER_ID)
			        {
			            SendClientMessage(playerid, Color_Blanco, "Usted no ha dado a nadie las llaves de este coche.");
			            return 1;
			        }
					Info[PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId]][pVehLlaves] = INVALID_PLAYER_VEHICLE_ID;
					Info[PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId]][pLlavesDeVeh] = INVALID_PLAYER_ID;
					format(string, sizeof(string), "%s ha tomado las llaves de su %s.", NombreP(playerid), GetVehicleName(PlayerVehicleInfo[playerid][listitem][pvId]));
					SendClientMessage(PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId], Color_Blanco, string);
					format(string, sizeof(string), "Tomaste las llaves de tu %s de %s.", GetVehicleName(PlayerVehicleInfo[playerid][listitem][pvId]),NombreP(PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId]));
					SendClientMessage(playerid, Color_Blanco, string);
					PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId] = INVALID_PLAYER_ID;
			    }
			}
			   	case CARSPAWN:
	    	{
	        	if (response == 1)
	        	{
	        		if(PlayerVehicleInfo[playerid][listitem][pvImpounded] == 1) return SendClientMessage(playerid,Color_Blanco,"El auto que intenta spawnear está embargado.");
			    	if(PlayerVehicleInfo[playerid][listitem][pvImpounded] >= 2) PlayerVehicleInfo[playerid][listitem][pvImpounded] = 0;
		        	if(PlayerVehicleInfo[playerid][listitem][pvModelId] != 0 && PlayerVehicleInfo[playerid][listitem][pvImpounded] == 0 && PlayerVehicleInfo[playerid][listitem][pvSpawned]== 0)
		        	{
		        	    if(carsforplayer[playerid] == 6) return SendClientMessage(playerid,Color_Blanco,"* Sólo puedes tener 6 coches spawneados y 2 guardados.");
		            	PlayerCars++;
		            	carsforplayer[playerid]++;
						new carcreated = CreateVehicle(PlayerVehicleInfo[playerid][listitem][pvModelId], PlayerVehicleInfo[playerid][listitem][pvPosX], PlayerVehicleInfo[playerid][listitem][pvPosY], PlayerVehicleInfo[playerid][listitem][pvPosZ], PlayerVehicleInfo[playerid][listitem][pvPosAngle],PlayerVehicleInfo[playerid][listitem][pvColor1], PlayerVehicleInfo[playerid][listitem][pvColor2], -1);
						PlayerVehicleInfo[playerid][listitem][pvId] = carcreated;
						VehicleFuel[carcreated] = PlayerVehicleInfo[playerid][listitem][pvFuel];
						SetVehicleHealth(carcreated, PlayerVehicleInfo[playerid][listitem][pvHealth]);
						SetVehicleVirtualWorld(carcreated, PlayerVehicleInfo[playerid][listitem][pvVW]);
						PlayerVehicleInfo[playerid][listitem][pvSpawned] = 1;
						SendClientMessage(playerid,Color_Blanco,"Vehiculo spawneado correctamente, en la última posición que lo estacionaste");
						if(PlayerVehicleInfo[playerid][listitem][pvLocked] == 1)
						LockPlayerVehicle(playerid, PlayerVehicleInfo[playerid][listitem][pvId], PlayerVehicleInfo[playerid][listitem][pvLock]);
	                    LoadPlayerVehicleMods(playerid, listitem);
						return 1;

					}
		        	else if(PlayerVehicleInfo[playerid][listitem][pvSpawned] == 1)
		        	{
					    new playername[MAX_PLAYER_NAME];
						GetPlayerName(playerid, playername, sizeof(playername));
						//printf(" Unloading %s's vehicles.", playername);
	         			new Float:health;
	            		GetVehicleHealth(PlayerVehicleInfo[playerid][listitem][pvId], health);
	            		if(health < 500) return SendClientMessage(playerid, Color_Blanco, " El vehiculo está muy dañado para ser guardado.");
	                    if(IsVehicleBusy(PlayerVehicleInfo[playerid][listitem][pvId])) return SendClientMessage(playerid, Color_Blanco, " El vehiculo está ocupado por otra persona y no puede ser guardado.");
						if(PlayerVehicleInfo[playerid][listitem][pvImpounded] >= 2) PlayerVehicleInfo[playerid][listitem][pvImpounded] = 0;
						if(PlayerVehicleInfo[playerid][listitem][pvId] != INVALID_PLAYER_VEHICLE_ID && PlayerVehicleInfo[playerid][listitem][pvImpounded] == 0 && PlayerVehicleInfo[playerid][listitem][pvSpawned]== 1)
						{
			            	PlayerCars--;
			            	carsforplayer[playerid]--;
	            			if(LockStatus[PlayerVehicleInfo[playerid][listitem][pvId]] != 0) LockStatus[PlayerVehicleInfo[playerid][listitem][pvId]] = 0;
	           		 		UpdatePlayerVehicleMods(playerid, listitem);
							DestroyVehicle(PlayerVehicleInfo[playerid][listitem][pvId]);
							VehicleFuel[PlayerVehicleInfo[playerid][listitem][pvId]] = 1000;
							PlayerVehicleInfo[playerid][listitem][pvId] = INVALID_PLAYER_VEHICLE_ID;
							PlayerVehicleInfo[playerid][listitem][pvSpawned] = 0;
							SendClientMessage(playerid,Color_Blanco,"Vehiculo fue guardado correctamente.");
							if(PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId] != INVALID_PLAYER_ID)
		    				{
		    	    			Info[PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId]][pVehLlaves] = INVALID_PLAYER_VEHICLE_ID;
		    	    			Info[PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId]][pLlavesDeVeh] = INVALID_PLAYER_ID;
		    					PlayerVehicleInfo[playerid][listitem][pvAllowedPlayerId] = INVALID_PLAYER_ID;
		    			}
		            }
				}
		    }
		}
	}	
	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

// > Comandos fuera de modulación o temporales.
CMD:darmeadmin(playerid, params[])
{
	Info[playerid][pAdmin] = 10;
	Info[playerid][pAdminEF] = 1;
	Info[playerid][pAdminTech] = 1;
	return 1;
}
CMD:gmx(playerid, params[])
{
	if(Info[playerid][pAdminTech] == 0) return Mensaje(playerid, Color_Bot, "sadsa");
	SendRconCommand("gmx");
	return 1;
}
// > Comandos | modulos.
#include <modulos/comandos/usuarios.inc>
#include <modulos/comandos/coches.inc>
#include <modulos/comandos/facciones.inc>
#include <modulos/comandos/admin/conces.inc>
#include <modulos/comandos/admin/general.inc>

#include <modulos/serverconfig/stocks.inc>