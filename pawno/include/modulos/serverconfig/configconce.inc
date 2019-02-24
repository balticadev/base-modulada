	new text_info[128];
	for(new d = 0; d < sizeof(CDSInfo); d++)
	{
		if(CDSInfo[d][cdEntranceX] != 0.0 && CDSInfo[d][cdEntranceY] != 0.0)
		{
			CDSInfo[d][cdPickupID] = CreateDynamicPickup(1239, 1, CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]);
			if(CDSInfo[d][cdOwned])
			{
	            format(text_info, sizeof(text_info),"{0673E6}Concesionario (%d) %s\n{FFFFFF}Dueño: {06E60E}%s", d,CDSInfo[d][cdMessage], CDSInfo[d][cdOwner]);
	            CDSInfo[d][cdTextLabel] = CreateDynamic3DTextLabel(text_info,Color_Azul,CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]+0.75,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
			}
			else
			{
	            format(text_info, sizeof(text_info),"Concesionario (%d) %s En Venta\nPrecio: %d", d,CDSInfo[d][cdMessage], CDSInfo[d][cdPrice]);
	            CDSInfo[d][cdTextLabel] = CreateDynamic3DTextLabel(text_info,Color_Bot,CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]+0.75,2.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1);
			}
		}
		for(new v = 0; v < MAX_DEALERSHIPVEHICLES; v++)
	    {
			if (CDSInfo[d][cdVehicleModel][v] != 0)
			{
		        new carcreated = CreateVehicle(CDSInfo[d][cdVehicleModel][v], CDSInfo[d][cdVehicleSpawnX][v], CDSInfo[d][cdVehicleSpawnY][v], CDSInfo[d][cdVehicleSpawnZ][v], CDSInfo[d][cdVehicleSpawnAngle][v], 0, 0, 6);
		        format(text_info, sizeof(text_info), "{0854FA}%s {FFFFFF}En Venta | {06E60E}Precio: %d", GetVehicleName(carcreated), CDSInfo[d][cdVehicleCost][v]);
                CDSInfo[d][cdVehicleLabel][v] = CreateDynamic3DTextLabel(text_info,Color_Blanco,0.0, 0.0, 0.0,8.0,INVALID_PLAYER_ID,carcreated);
                CDSInfo[d][cdVehicleId][v] = carcreated;
			}
		}
	}