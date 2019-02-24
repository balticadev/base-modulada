CMD:adminconce(playerid, params[])
{
	if(Info[playerid][pAdmin] < 10) return SendClientMessage(playerid, Color_Blanco,"No puedes usar este comando!");
	if(IsPlayerConnected(playerid))
	SendClientMessage(playerid, Color_Bot, "Comandos administrativos para los Concesionarios:");
	SendClientMessage(playerid, Color_Blanco, "/editConcesionario - /editcoche - /vConcesionario - cConcesionario");
	SendClientMessage(playerid, Color_Blanco, "/createcdveh /destroycdveh /cconse [Crear Concesionario] /dconse [Borrar Concesionario]");
	return 1;
}
CMD:editconcesionario(playerid, params[])
{
    for(new d = 0 ; d < MAX_CARDEALERSHIPS; d++)
	{
        if(IsPlayerInRangeOfPoint(playerid, CDSInfo[d][cdRadius], CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ])) {
            if(IsPlayerOwnerOfCDEx(playerid, d))
			{
                SetPVarInt(playerid, "editingcd", d);
                SetPVarInt(playerid, "editingcdveh", -1);
                SetPVarInt(playerid, "editingcdvehpos", 0);
                SetPVarInt(playerid, "editingcdvehnew", 0);
                new listitems[] = "1 Nuevo Coche\n2 Mis Coches\n3 Mejorar\n4 Ganancias";
                ShowPlayerDialog(playerid,DIALOG_CDEDIT,DIALOG_STYLE_LIST,"Elige y continuar", listitems,"Ok","Cancelar");
                return 1;




            }
        }
    }
    SendClientMessage(playerid, Color_Blanco, "ERROR: Debes estar de pie dentro del radio del Concesionario.");
    return 1;
}

CMD:editcoche(playerid, params[])
{
    new vehicleid = GetPlayerVehicleID(playerid);
    new v, d;
    v = GetCarDealershipVehicleId(vehicleid);
    d = GetCarDealershipId(vehicleid);
    if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, Color_Blanco, "ERROR: Usted no está en un coche.");
    if(v != -1 && d != -1)
	{
        if(IsPlayerOwnerOfCDEx(playerid, d))
		{
            SetPVarInt(playerid, "editingcd", d);
            SetPVarInt(playerid, "editingcdveh", v);
            SetPVarInt(playerid, "editingcdvehpos", 0);
            SetPVarInt(playerid, "editingcdvehnew", 0);
            new listitems[] = "1 Editar Modelo\n2 Editar Costo\n3 Editar Park\n4 Borrar Coche";
            ShowPlayerDialog(playerid,DIALOG_CDEDITONE,DIALOG_STYLE_LIST,"Concesionario:", listitems,"Ok","Cancelar");
            return 1;
        }
        else
		{
            SendClientMessage(playerid, Color_Blanco, "ERROR: Usted no es dueño de este Concesionario.");
        }
    }
    else
	{
        SendClientMessage(playerid, Color_Blanco, "ERROR: El coche no es parte de un Concesionario.");
    }
    return 1;
}

CMD:vconcesionario(playerid, params[])
{
	new string[128];

    for(new d = 0 ; d < MAX_CARDEALERSHIPS; d++)
	{
        if(IsPlayerInRangeOfPoint(playerid, 3.0, CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]))
		{
            if(IsPlayerOwnerOfCDEx(playerid, d))
			{
                SetPVarInt(playerid, "editingcd", d);
                format(string,128,"¿Seguro que deseas vender este Concesionario de coches por $%d?\n.", CDSInfo[d][cdPrice] / 2);
                ShowPlayerDialog(playerid,DIALOG_CDSELL,DIALOG_STYLE_MSGBOX,"Advertencia:",string,"Vender","Cancelar");
                return 1;
            }
            else
			{
                SendClientMessage(playerid, Color_Blanco, "Usted no es el dueño de este Concesionario de coches.");
                return 1;
            }
        }
    }
    SendClientMessage(playerid, Color_Blanco, "Usted tiene que estar cerca de un Concesionario de coches.");
    return 1;
}

CMD:cconcesionario(playerid, params[])
{
    for(new d = 0 ; d < MAX_CARDEALERSHIPS; d++)
	{
        if(IsPlayerInRangeOfPoint(playerid, 3.0, CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]))
		{
            if(!CDSInfo[d][cdOwned])
			{
                if(GetPVarInt(playerid, "Cash") < CDSInfo[d][cdPrice])
				{
                    SendClientMessage(playerid, Color_Blanco, " No tienes suficiente dinero para comprar el Concesionario de coches.");
                    return 1;
                }
                SetPVarInt(playerid, "Cash", GetPVarInt(playerid, "Cash")-CDSInfo[d][cdPrice]);
                SetPlayerOwnerOfCD(playerid, d);
                SendClientMessage(playerid, Color_Blanco, " Felicitaciones, por su nueva compra.");
                SendClientMessage(playerid, Color_Blanco, " usa /soporte para ver la sección de Concesionario para ver más información.");
                SendClientMessage(playerid, Color_Blanco, " Por favor establece la posición que quieres que los coches den spawn.");
                SendClientMessage(playerid, Color_Blanco, " Ponte en el lugar deseado, una vez listo usa el botón FIRE (CLICK).");
                SendClientMessage(playerid, Color_Blanco, " Nota: Si no estableces los coches sus clientes no podrán comprar autos.");
                SetPVarInt(playerid, "editingcdvehpos", 2);
                SetPVarInt(playerid, "editingcd", d);
                return 1;
            }
            else
			{
                SendClientMessage(playerid, Color_Blanco, "Este Concesionario no está en venta.");
            }
        }
    }
    return 1;
}

CMD:createcdveh(playerid, params[])
{
    if (Info[playerid][pAdmin] < 9)
	{
        SendClientMessage(playerid, Color_Blanco, " No puedes usar este comando.");
        return 1;
    }

    new string[128], price, dealershipid, modelid;
    if(sscanf(params, "ddd", price, dealershipid, modelid)) return SendClientMessage(playerid, Color_Blanco, "USA: /createcdveh [price] [dealership] [modelid]");

    new Float:X,Float:Y,Float:Z,Float:A;
    GetPlayerPos(playerid,X,Y,Z);
    GetPlayerFacingAngle(playerid, A);
    new cdvehicleid = CreateCarDealershipVehicle(dealershipid, modelid, X, Y, Z, A, price);
    if(cdvehicleid == -1)
	{
        SendClientMessage(playerid, Color_Blanco, "ERROR: cdVehicles ha alcanzado el límite.");
    }
    else
	{
        format(string, sizeof(string), " Coche creado con la ID %d.", cdvehicleid);
        SendClientMessage(playerid, Color_Blanco, string);
    }
    return 1;
}

CMD:destroycdveh(playerid, params[])
{
    if (Info[playerid][pAdmin] < 9)
	{
        SendClientMessage(playerid, Color_Blanco, " No puedes usar este comando.");
        return 1;
    }

    new string[128], vehid;
    if(sscanf(params, "d", vehid)) return SendClientMessage(playerid, Color_Blanco, "USA: /destroycdveh [vehicleid]");

    DestroyCarDealershipVehicle(GetCarDealershipId(vehid), GetCarDealershipVehicleId(vehid));
    SavecDealership(GetCarDealershipId(vehid));
    format(string, sizeof(string), " Coche eliminado - ID %d.", vehid);
    SendClientMessage(playerid, Color_Blanco, string);
    return 1;
}

CMD:cconse(playerid, params[])
{
    if (Info[playerid][pAdmin] < 9)
	{
        SendClientMessage(playerid, Color_Blanco, " You are not allowed to use this command.");
        return 1;
    }

    new string[128], price, radius, message[64];
    if(sscanf(params, "dds[64]", price, radius, message)) return SendClientMessage(playerid, Color_Blanco, "USA: /cconse [price] [radius] [message]");

    new Float:X,Float:Y,Float:Z;
    GetPlayerPos(playerid,X,Y,Z);
    new dealershipid = CreateCarDealership(X, Y, Z, radius, price, message);
    if(dealershipid == -1)
	{
        SendClientMessage(playerid, Color_Blanco, "ERROR: Concesionarios llegó al limite.");
    }
    else
	{
        format(string, sizeof(string), " Concesionario creado - ID %d.", dealershipid);
        SendClientMessage(playerid, Color_Blanco, string);
    }
    return 1;
}

CMD:dconse(playerid, params[])
{
    if (Info[playerid][pAdmin] < 9)
	{
        SendClientMessage(playerid, Color_Blanco, " No puedes usar este comando.");
        return 1;
    }

    new string[128], dealershipid;
    if(sscanf(params, "d", dealershipid)) return SendClientMessage(playerid, Color_Blanco, "USA: /dconse [dealershipid]");

    for(new d = 0 ; d < MAX_CARDEALERSHIPS; d++)
	{
        if(IsPlayerInRangeOfPoint(playerid, 3.0, CDSInfo[d][cdEntranceX], CDSInfo[d][cdEntranceY], CDSInfo[d][cdEntranceZ]))
		{
            DestroyCarDealership(d);
            format(string, sizeof(string), " Concesionario destruido - ID %d.", d);
            SendClientMessage(playerid, Color_Blanco, string);
            return 1;
        }
    }
    if(dealershipid > MAX_CARDEALERSHIPS) return 1;
    if(dealershipid < 0) return 1;
    DestroyCarDealership(dealershipid);
    format(string, sizeof(string), " Concesionario destruido - ID %d.", dealershipid);
    SendClientMessage(playerid, Color_Blanco, string);
    return 1;
}