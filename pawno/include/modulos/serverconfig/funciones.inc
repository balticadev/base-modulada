funcion IngresarInfo(playerid)
{
	SetSpawnInfo(playerid,0,Info[playerid][pSkin],Info[playerid][px],Info[playerid][py],Info[playerid][pz],0,0,0,0,0,0,0);
	SetPlayerSkin(playerid,Info[playerid][pSkin]);
	SetPlayerPos(playerid,Info[playerid][px],Info[playerid][py],Info[playerid][pz]);
	DarDinero(playerid,Info[playerid][pMoney]);
	DarChaleco(playerid,Info[playerid][Chaleco]);
	DarVida(playerid,Info[playerid][pVida]);
	SpawnPlayer(playerid);
	return 1;
}
funcion ElecSex(playerid)
{
	ShowPlayerDialog(playerid,Dialogo_Sexo,DIALOG_STYLE_LIST,"Escoge el sexo que quieres ser","Hombre\nMujer","Aceptar","");
	return 1;
}
funcion ElecEdad(playerid)
{
	ShowPlayerDialog(playerid,Dialogo_Edad,DIALOG_STYLE_INPUT,"Elige Tu edad","Ingresa tu edad tiene que ser mayor que 0 o menor que 99","Elegir","");
	return 1;
}
funcion ColocarJ(playerid)
{
	GuardarCuenta(playerid);
	SpawnPlayer(playerid);
	return 1;
}
funcion Estadisticas(playerid)
{
	new nivel = Info[playerid][pLevel],Edad = Info[playerid][pEdad],Muertes = Info[playerid][pMuertes], Sex = Info[playerid][pSex], Trab = Info[playerid][pTrab], Fac = Info[playerid][pFac],Rang = Info[playerid][pRang],Dinero = GetPlayerMoney(playerid),Busq = Info[playerid][pBuq];
	new string[250],N[50],N2[50],N3[50],N4[50],st[250];
	switch(Fac)
	{
		case 0: format(N,sizeof(N),"Ninguna");
		case 1: format(N,sizeof(N),"Policia");
	}
	switch(Trab)
	{
		case 0: format(N2,sizeof(N2),"Ninguno");
		case 1: format(N2,sizeof(N2),"Camionero");
	}
	switch(Sex)
	{
		case 0: format(N3,sizeof(N3),"Hombre");
		case 1: format(N3,sizeof(N3),"Mujer");
	}
	if(Info[playerid][pFac] == 1)
	{
		switch(Rang)
		{
			case 0: format(N4,sizeof(N4),"Ninguno");
			case 1: format(N4,sizeof(N4),"Cadete");
			case 2: format(N4,sizeof(N4),"Cadete II");
			case 3: format(N4,sizeof(N4),"Sargento");
			case 4:	format(N4,sizeof(N4),"Investigador");
			case 5:	format(N4,sizeof(N4),"Capitan");
			case 6: format(N4,sizeof(N4),"Comandante");
		}
	}
	new pastn = levelexp*Info[playerid][pLevel];
	format(st,sizeof(st),"Edad: %d\n Nivel: %d\nExperiencia: %d/%d \n Muertes: %d \n Sexo: %s \n Faccion: %s \n Rango: %s \n Trabajo: %s\n Dinero: %d\n Nivel De busqueda: %d",Edad,nivel,Info[playerid][pLevelExp],pastn,Muertes,N3,N,N4,N2,Dinero,Busq);
	strcat(string,st,sizeof(string));
	ShowPlayerDialog(playerid,Dialogo_Est,DIALOG_STYLE_MSGBOX,"Estadisticas",string,"Aceptar","");
	return 1;
}
funcion GetPlayerVehicleCount(playerid){
	new cars = 0;
	for(new i = 0; i < MAX_PLAYERVEHICLES; i++){
	    if(PlayerVehicleInfo[playerid][i][pvModelId]){
	        if(PlayerVehicleInfo[playerid][i][pvId] != INVALID_PLAYER_VEHICLE_ID && PlayerVehicleInfo[playerid][i][pvImpounded] == 0 && PlayerVehicleInfo[playerid][i][pvSpawned] == 1){
				if(CheckPlayerVehicleForDesync(playerid, PlayerVehicleInfo[playerid][i][pvId])) return 0;
				cars++;
			}
	    }
	}
	return cars;
}

funcion VehicleCount(playerid){
    new cars = 0;
    for(new i = 0; i < MAX_PLAYERVEHICLES; i++){
		if(PlayerVehicleInfo[playerid][i][pvModelId] != 0){
			cars++;
		}
    }
    return cars;
}
funcion CheckPlayerVehicleForDesync(playerid, vehicleid)
{
	if(GetVehicleModel(vehicleid) < 400 || GetVehicleModel(vehicleid) > 611)
	{
    	SendClientMessage(playerid, Color_Blanco, "Error: Desincronización de vehículos detectado, ejecutando sincronización de sus vehículos...");
    	UnloadPlayerVehicles(playerid);
    	//LoadPlayerVehicles(playerid);
    	SendClientMessage(playerid, Color_Blanco, "Sus vehículos han sido sincronizados con el servidor.");
    	return 1;
	}
	return 0;
}
funcion NombreP(playerid)
{
new Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name));
new P;
while ((P = strfind(Name, "_", false, P)) != -1) Name[P] = ' ';
return 1;
}
forward SendRadioMessage(member, color, string[]); public SendRadioMessage(member, color, string[])
{
	foreach(Player, i)
	{
		if(Info[i][pFac] == member)
		{
				SendClientMessage(i, color, string);
		}
	}
	return 1;
}
funcion Muertos(playerid)
{
new string[250];
format(string,sizeof(string),"{FFFFF}Espera a los {00FF00}paramedicos {FFFFF}estas herido");
SendClientMessage(playerid,Color_Blanco,string);
DarVida(playerid,100);
SetPlayerPos(playerid,Info[playerid][px],Info[playerid][py],Info[playerid][pz]);
ApplyAnimation(playerid,"CRACK","crckdeth1",4.1,1,0,0,1,0);
Hospi[playerid] = SetTimerEx("Hospital",1000,true,"i",playerid);
Vida[playerid] = SetTimerEx("BajaVida",2500,true,"i",playerid);
SetPlayerCameraPos(playerid, 1224.2689, -1383.1715, 56.3110);
SetPlayerCameraLookAt(playerid, 1223.4327, -1382.6150, 55.6309);
return 1;
}
funcion Hospital(playerid)
{
	new Float:Health; GetPlayerHealth(playerid,Health);
	if(Health == 0)
	{
		GameTextForPlayer(playerid,"Has muerto",2500,2);
		KillTimer(Hospi[playerid]);
		KillTimer(Vida[playerid]);
		Muerto[playerid] = false;
		MHospital[playerid] = true;
		SpawnPlayer(playerid);
	}
	return 1;
}
funcion BajaVida(playerid)
{
	new Float:Health; GetPlayerHealth(playerid,Health);
	if(Health > 0)
	{
		DarVida(playerid,Health-25);
	}
	return 1;
}
funcion TextoInicio(playerid)
{
	TextDrawShowForPlayer(playerid,Textdraw0);
	TextDrawShowForPlayer(playerid,Textdraw1);
	TextDrawShowForPlayer(playerid,Textdraw2);
	TextDrawShowForPlayer(playerid,Textdraw3);
	TextDrawShowForPlayer(playerid,Textdraw4);
	TextDrawShowForPlayer(playerid,Textdraw5);
	TextDrawShowForPlayer(playerid,Textdraw6);
	return 1;
}
funcion ChaoTexto(playerid)
{
	TextDrawHideForPlayer(playerid,Textdraw0);
	TextDrawHideForPlayer(playerid,Textdraw1);
	TextDrawHideForPlayer(playerid,Textdraw2);
	TextDrawHideForPlayer(playerid,Textdraw3);
	TextDrawHideForPlayer(playerid,Textdraw4);
	TextDrawHideForPlayer(playerid,Textdraw5);
 	TextDrawHideForPlayer(playerid,Textdraw6);
	return 1;
}
funcion Kickeado(playerid) return Kick(playerid);