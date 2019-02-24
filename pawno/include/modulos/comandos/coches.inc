CMD:aceptar(playerid, params[])
{
	new sendername[MAX_PLAYER_NAME], giveplayer[MAX_PLAYER_NAME], string[128];
	if(IsPlayerConnected(playerid))
	{
		if(strcmp(params,"coche",true) == 0) {
            if(VehicleOffer[playerid] < 999) {
                if(IsPlayerConnected(VehicleOffer[playerid])) {
                    if(GetPlayerCash(playerid) > VehiclePrice[playerid]) {
                        if(IsPlayerInVehicle(VehicleOffer[playerid], PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvId]))
						{
                            if(!ProxDetectorS(8.0, VehicleOffer[playerid], playerid)) return SendClientMessage(playerid, Color_Blanco, "No estás cerca del que te va a vender");
                            new playervehicleid = GetPlayerFreeVehicleId(playerid);
                            new carsamount = VehicleCount(playerid);
                            if(Info[playerid][pVIP] == 0 && carsamount >= 2) return SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, usuarios normales sólo pueden tener 2 coches.");
                            if(Info[playerid][pVIP] == 1 && carsamount >= 4) return SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, BVIP Sólo puede tener 4 coches.");
                            if(Info[playerid][pVIP] == 2 && carsamount >= 5) return SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, SVIP Sólo puede tener 5 coches.");
                            if(Info[playerid][pVIP] == 3 && carsamount >= 7) return SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, GVIP Sólo puede tener 7 coches.");
                            if(Info[playerid][pVIP] == 4 && carsamount >= 8) return SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más coches, PVIP Sólo puede tener 8 coches.");
							if(playervehicleid == -1) return SendClientMessage(playerid, Color_Blanco, "ERROR: No puedes tener más autos.");
                            new ip[32], ipex[32];
                            GetPlayerIp(playerid, ip, sizeof(ip));
                            GetPlayerIp(VehicleOffer[playerid], ipex, sizeof(ipex));
                            format(string, sizeof(string), "[CAR] %s (IP: %s) pagó $%d a %s por el %s (IP: %s)", NombreP(playerid), ip, VehiclePrice[playerid], NombreP(VehicleOffer[playerid]), GetVehicleName(PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvId]), ipex);
                            GetPlayerName(VehicleOffer[playerid], giveplayer, sizeof(giveplayer));
                            GetPlayerName(playerid, sendername, sizeof(sendername));
                            format(string, sizeof(string), "* Has pagado por un %s, $%d, de %s. (Usa /soporte > coche para más información)", GetVehicleName(PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvId]), VehiclePrice[playerid],giveplayer);
                            SendClientMessage(playerid, Color_Azul, string);
                            format(string, sizeof(string), "* Vendiste tu %s a %s por $%d.",GetVehicleName(PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvId]), sendername,VehiclePrice[playerid]);
                            SendClientMessage(VehicleOffer[playerid], Color_Azul, string);
                           	DarDinero( VehicleOffer[playerid], VehiclePrice[playerid] );
                           	DarDinero(playerid, -VehiclePrice[playerid]);
                            RemovePlayerFromVehicle(VehicleOffer[playerid]);
                            new Float:slx, Float:sly, Float:slz;
                            GetPlayerPos(VehicleOffer[playerid], slx, sly, slz);
                            SetPlayerPos(VehicleOffer[playerid], slx, sly, slz+2);
                            PlayerVehicleInfo[playerid][playervehicleid][pvId] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvId];
                            PlayerVehicleInfo[playerid][playervehicleid][pvModelId] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvModelId];
                            PlayerVehicleInfo[playerid][playervehicleid][pvPosX] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPosX];
                            PlayerVehicleInfo[playerid][playervehicleid][pvPosY] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPosY];
                           	PlayerVehicleInfo[playerid][playervehicleid][pvPosZ] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPosZ];
                           	PlayerVehicleInfo[playerid][playervehicleid][pvPosAngle] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPosAngle];
                            PlayerVehicleInfo[playerid][playervehicleid][pvVW] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvVW];
							PlayerVehicleInfo[playerid][playervehicleid][pvLock] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvLock];
                           	PlayerVehicleInfo[playerid][playervehicleid][pvLocked] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvLocked];
                            PlayerVehicleInfo[playerid][playervehicleid][pvPaintJob] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPaintJob];
                            PlayerVehicleInfo[playerid][playervehicleid][pvColor1] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvColor1];
                            PlayerVehicleInfo[playerid][playervehicleid][pvColor2] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvColor2];
                            strmid(PlayerVehicleInfo[playerid][playervehicleid][pvAllowPlayer], PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvAllowPlayer], 0, strlen(PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvAllowPlayer]), 255);
                            PlayerVehicleInfo[playerid][playervehicleid][pvAllowedPlayerId] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvAllowedPlayerId];
                            PlayerVehicleInfo[playerid][playervehicleid][pvPark] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPark];
                            PlayerVehicleInfo[playerid][playervehicleid][pvPrice] = VehiclePrice[playerid];
                            PlayerVehicleInfo[playerid][playervehicleid][pvSpawned] = 1;
                            carsforplayer[playerid]++;
                            for(new m = 0; m < MAX_MODS; m++)
                            {
                                PlayerVehicleInfo[playerid][playervehicleid][pvMods][m] = PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvMods][m];
                            }
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvId] = 0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvModelId] = 0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPosX] = 0.0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPosY] = 0.0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPosZ] = 0.0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPosAngle] = 0.0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvVW] = 0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvLock] = 0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvLocked] = 0;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPaintJob] = -1;
                            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvColor1] = 0;
							PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvImpounded] = 0;
               	           	PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvColor2] = 0;
             	            strmid(PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvAllowPlayer], "Nadie", 0, strlen("Nadie"), 255);
                	        PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvAllowedPlayerId] = INVALID_PLAYER_ID;
                	        PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPark] = 0;
                	        PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvPrice] = 0;
                	        PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvSpawned] = 0;
                	        carsforplayer[VehicleOffer[playerid]]++;
                	        for(new m = 0; m < MAX_MODS; m++) 
                	        {
                	            PlayerVehicleInfo[VehicleOffer[playerid]][VehicleId[playerid]][pvMods][m] = 0;
                	        }
                	        VehicleOffer[playerid] = 999;
                	        VehiclePrice[playerid] = 0;
                	        return 1;
                	    }
                	    else return SendClientMessage(playerid, Color_Blanco, "   El que te va a vender no está en el coche.");
                	}
                	else return SendClientMessage(playerid, Color_Blanco, "   No puedes pagar este coche!");
               	}
                return 1;
            }
           	else return SendClientMessage(playerid, Color_Blanco, "   Nadie te ha ofrecido un coche!");
        }
	}
	return 1;
}
CMD:estacionar(playerid, params[])
{
	if(Info[playerid][pLlavesDeVeh] != INVALID_PLAYER_ID)
	{
		new ownerid = Info[playerid][pLlavesDeVeh];
		if(IsPlayerConnected(ownerid))
		{
			new d = Info[playerid][pVehLlaves];
			if(IsPlayerInVehicle(playerid, PlayerVehicleInfo[ownerid][d][pvId]))
			{
			    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, Color_Blanco, "Tu debes ser el conductor.");
				new Float:x, Float:y, Float:z, Float:angle, Float:health;
				GetVehicleHealth(PlayerVehicleInfo[ownerid][d][pvId], health);
				PlayerVehicleInfo[ownerid][d][pvHealth] = health;
				//if(health < 800) return SendClientMessage(playerid, Color_Blanco, " Tu vehículo está demasiado dañado para estacionarlo.");
				if(Info[playerid][pLockCar] == GetPlayerVehicleID(playerid)) Info[playerid][pLockCar] = INVALID_VEHICLE_ID;
				GetVehiclePos(PlayerVehicleInfo[ownerid][d][pvId], x, y, z);
				GetVehicleZAngle(PlayerVehicleInfo[ownerid][d][pvId], angle);
				SurfingCheck(GetPlayerVehicleID(playerid));
				UpdatePlayerVehicleParkPosition(ownerid, d, x, y, z, angle, health);
				PutPlayerInVehicle(playerid, GetPlayerVehicleID(playerid), 0);
			 	SetPlayerArmedWeapon(playerid, 0);

				new string[29 + (MAX_PLAYER_NAME * 2)];
				format(string, sizeof(string), "* %s ha estacionado el vehiculo de %s.", NombreP(playerid), NombreP(ownerid));
				ProxDetector(30.0, playerid, string, ME_COLOR,ME_COLOR,ME_COLOR,ME_COLOR,ME_COLOR);
                fVehSpeed[playerid] = 0.0;
				return 1;
			}
		}
	}
	for(new d = 0 ; d < MAX_PLAYERVEHICLES; d++)
	{
		if(IsPlayerInVehicle(playerid, PlayerVehicleInfo[playerid][d][pvId]))
		{
		    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendClientMessage(playerid, Color_Blanco, "Tu debes ser el conductor.");
			new Float:x, Float:y, Float:z, Float:angle, Float:health;
			GetVehicleHealth(PlayerVehicleInfo[playerid][d][pvId], health);
			PlayerVehicleInfo[playerid][d][pvHealth] = health;
			//if(health < 800) return SendClientMessage(playerid, Color_Blanco, " Tu vehiculo está muy dañado para estacionarlo.");
			if(Info[playerid][pLockCar] == GetPlayerVehicleID(playerid)) Info[playerid][pLockCar] = INVALID_VEHICLE_ID;
			GetVehiclePos(PlayerVehicleInfo[playerid][d][pvId], x, y, z);
			GetVehicleZAngle(PlayerVehicleInfo[playerid][d][pvId], angle);
			SurfingCheck(GetPlayerVehicleID(playerid));
			UpdatePlayerVehicleParkPosition(playerid, d, x, y, z, angle, health);
			PutPlayerInVehicle(playerid, PlayerVehicleInfo[playerid][d][pvId], 0);
			SetPlayerArmedWeapon(playerid, 0);

			new string[30 + (MAX_PLAYER_NAME * 2)];
			format(string, sizeof(string), "* %s ha estacionado su vehiculo.", NombreP(playerid));
			ProxDetector(30.0, playerid, string, ME_COLOR,ME_COLOR,ME_COLOR,ME_COLOR,ME_COLOR);
            fVehSpeed[playerid] = 0.0;
			return 1;
		}
	}
	SendClientMessage(playerid, Color_Blanco, "Tu necesitas estar dentro de tu vehiculo para hacer esto.");
	return 1;
}

CMD:borrarcoche(playerid, params[])
{
	if(GetPVarInt(playerid, "dcConfirm") == 0)
	{
		SetPVarInt(playerid, "dcConfirm", 1);
		SendClientMessage(playerid, Color_Blanco, "El uso de este comando borrará completamente el vehículo y no habrá reembolso");
		SendClientMessage(playerid, Color_Blanco, "Si estás seguro de que deseas eliminar tu vehículo, por favor re-escriba el comando /borrarcoche");
	}
	else
	{
		DeletePVar(playerid, "dcConfirm");
		for(new d = 0 ; d < MAX_PLAYERVEHICLES; d++)
		{
			if(IsPlayerInVehicle(playerid, PlayerVehicleInfo[playerid][d][pvId]))
			{
			    carsforplayer[playerid]--;
				DestroyVehicle(PlayerVehicleInfo[playerid][d][pvId]);
				PlayerVehicleInfo[playerid][d][pvId] = 0;
                PlayerVehicleInfo[playerid][d][pvModelId] = 0;
				PlayerVehicleInfo[playerid][d][pvPosX] = 0.0;
				PlayerVehicleInfo[playerid][d][pvPosY] = 0.0;
				PlayerVehicleInfo[playerid][d][pvPosZ] = 0.0;
				PlayerVehicleInfo[playerid][d][pvPosAngle] = 0.0;
				PlayerVehicleInfo[playerid][d][pvLock] = 0;
				PlayerVehicleInfo[playerid][d][pvLocked] = 0;
				PlayerVehicleInfo[playerid][d][pvPaintJob] = -1;
				PlayerVehicleInfo[playerid][d][pvColor1] = 0;
				PlayerVehicleInfo[playerid][d][pvColor2] = 0;
				PlayerVehicleInfo[playerid][d][pvPrice] = 0;
				PlayerVehicleInfo[playerid][d][pvImpounded] = 0;
				strcpy(PlayerVehicleInfo[playerid][d][pvAllowPlayer], "Nadie", MAX_PLAYER_NAME);
				PlayerVehicleInfo[playerid][d][pvPark] = 0;
				PlayerVehicleInfo[playerid][d][pvAllowedPlayerId] = INVALID_PLAYER_ID;
				for(new m = 0; m < MAX_MODS; m++)
				{
					PlayerVehicleInfo[playerid][d][pvMods][m] = 0;
				}
				PlayerCars--;
				SendClientMessage(playerid, Color_Blanco, "Su vehículo ha sido borrado.");
				return 1;
			}
		}
		SendClientMessage(playerid, Color_Blanco, " Tienes que estar dentro de tu vehiculo.");
	}

	return 1;
}

CMD:deletecp(playerid, params[])
{
	new string[128], giveplayerid, vehicleid;
	if(sscanf(params, "dd", giveplayerid, vehicleid)) return SendClientMessage(playerid, Color_Blanco, "USA: /deletecp [playerid] [vehicleid]");
    if (Info[playerid][pAdmin] < 5)
    {
    	SendClientMessage(playerid, Color_Blanco, " No puedes utilizar este comando.");
     	return 1;
   	}
	format(string, sizeof(string), "%s ha destruido el auto %s de %s.", NombreP(playerid), GetVehicleName(vehicleid), NombreP(giveplayerid));
	new playervehicleid = GetPlayerVehicle(giveplayerid, vehicleid);
	if(playervehicleid == -1) return SendClientMessage(playerid, Color_Blanco, "ERROR: El jugador no tiene ese vehículo.");
	DestroyPlayerVehicle(giveplayerid, playervehicleid);
	return 1;
}

CMD:quitarllave(playerid, params[])
{
    new vstring[512], iValidVehicles;
	for(new i=0; i<MAX_PLAYERVEHICLES; i++)
	{
	    if(PlayerVehicleInfo[playerid][i][pvId] != INVALID_PLAYER_VEHICLE_ID)
			format(vstring, sizeof(vstring), "%s\n%s (ID: %d)", vstring, GetVehicleName(PlayerVehicleInfo[playerid][i][pvId]), NombreP(PlayerVehicleInfo[playerid][i][pvAllowedPlayerId])), ++iValidVehicles;

        else if(PlayerVehicleInfo[playerid][i][pvImpounded] == 1)
            format(vstring, sizeof(vstring), "%s\n%s (Embargado)", vstring, VehicleName[PlayerVehicleInfo[playerid][i][pvModelId] - 400]);

        else
			format(vstring, sizeof(vstring), "%s\nVacío", vstring);
	}
	if(iValidVehicles != 0)
	{
		ShowPlayerDialog(playerid, REMOVEKEYS, DIALOG_STYLE_LIST, "Por favor selecciona un vehiculo.", vstring, "Quitar", "Cancelar");
	}
	else
	{
	    SendClientMessage(playerid, Color_Blanco, "Usted no tiene ninguna llave para quitar.");
	}
	return 1;
}

CMD:coches(playerid, params[])
{
    if(carsforplayer[playerid] == 0) return SendClientMessage(playerid, Color_Blanco, "Recuerda antes de usar tu GPS tienes que tener al menos un coche spawneado. (/llaves)");
	new vstring[1024];
	for(new i; i < MAX_PLAYERVEHICLES; i++)
	{
		if(PlayerVehicleInfo[playerid][i][pvId] > INVALID_PLAYER_VEHICLE_ID)
		{
			format(vstring, sizeof(vstring), "%s\n%s (ID: %d)", vstring, VehicleName[PlayerVehicleInfo[playerid][i][pvModelId] - 400], PlayerVehicleInfo[playerid][i][pvId]);
		}
		else if(PlayerVehicleInfo[playerid][i][pvImpounded] == 1)
		{
			format(vstring, sizeof(vstring), "%s\n%s (Embargado)", vstring, VehicleName[PlayerVehicleInfo[playerid][i][pvModelId] - 400]);
		}
		else
		{
			format(vstring, sizeof(vstring), "%s\nVacío", vstring);
		}
	}
	ShowPlayerDialog(playerid, TRACKCAR,DIALOG_STYLE_MSGBOX, "Coches", vstring, "Aceptar", "Salir");
	return 1;
}