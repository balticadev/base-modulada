CMD:daradmin(playerid,params[])
{
	if(Info[playerid][pAdminES] == 0) return SendClientMessage(playerid,Color_Blanco,"No tienes la asignacion necesaria para esto");
	ShowPlayerDialog(playerid,Dialog_dAdmin,DIALOG_STYLE_INPUT,"Quieres Dar Admin","Ingresa La ID abajo","Aceptar","Salir");
	return 1;
}
CMD:expulsar(playerid,params[])
{
	new id,string[250],Name[MAX_PLAYER_NAME],pName[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name)); GetPlayerName(id,pName,sizeof(pName));
	if(Info[playerid][pAdmin] < 2) return SendClientMessage(playerid,Color_Blanco,"No tienes el nivel necesario para esto");
	if(sscanf(params,"d",id))return SendClientMessage(playerid,Color_Blanco,"Usa /expulsar [ID]");
	if(!IsPlayerConnected(id))return SendClientMessage(playerid,Color_Blanco,"Id Invalida");
	if(Info[playerid][pAdmin] < Info[id][pAdmin]) return SendClientMessage(playerid,Color_Blanco,"Lo Siento No puedes kickear a Nivel admin mas alto que tu"), Kick(playerid);
	Kick(id);
	format(string,sizeof(string),"%s Expulso a %s",Name,pName);
	AdminMensaje(Color_Bot,string);
	return 1;
}
CMD:traer(playerid,params[])
{
	new id,string[250],Name[MAX_PLAYER_NAME],pName[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name)); GetPlayerName(id,pName,sizeof(pName));
	if(Info[playerid][pAdmin] == 0) return SendClientMessage(playerid,Color_Blanco,"No tienes el nivel necesario para esto");
	if(sscanf(params,"d",id))return SendClientMessage(playerid,Color_Blanco,"Usa /traer [ID]");
	if(!IsPlayerConnected(id))return SendClientMessage(playerid,Color_Blanco,"Id Invalida");
	if(Info[playerid][pAdmin] < Info[id][pAdmin]) return SendClientMessage(playerid,Color_Bot,"Lo siento no puedes traer a ese jugador");
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	SetPlayerPos(id,x,y,z);
	format(string,sizeof(string),"%s llevo a su posicion a %s",Name,pName);
	AdminMensaje(Color_Blanco,string);
	return 1;
}
CMD:ir(playerid,params[])
{
	new id,string[250],Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name));
	if(Info[playerid][pAdmin] == 0) return SendClientMessage(playerid,Color_Blanco,"No tienes el nivel necesario para esto");
	if(sscanf(params,"d",id))return SendClientMessage(playerid,Color_Blanco,"Usa /ir [ID]");
	if(!IsPlayerConnected(id))return SendClientMessage(playerid,Color_Blanco,"Id Invalida");
	new Float:x,Float:y,Float:z;
	GetPlayerPos(id,x,y,z);
	SetPlayerPos(playerid,x,y,z);
	format(string,sizeof(string),"%s fue a su posicion",Name);
	SendClientMessage(id,Color_Blanco,string);
	return 1;
}
CMD:darnivel(playerid,params[])
{
	new id,niv,string[250],Name[MAX_PLAYER_NAME],pName[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name));
	if(Info[playerid][pAdmin] < 10) return SendClientMessage(playerid,Color_Blanco,"No tienes el nivel necesario para esto");
	if(sscanf(params,"dd",id,niv))return SendClientMessage(playerid,Color_Blanco,"Usa /darnivel [ID][Nivel]");
	if(!IsPlayerConnected(id))return SendClientMessage(playerid,Color_Blanco,"Id Invalida");
	GetPlayerName(id,pName,sizeof(pName));
	Info[id][pLevel] = niv;
	format(string,sizeof(string),"%s le dio nivel a %s %d",Name,pName,niv);
	AdminMensaje(Color_Blanco,string);
	return 1;
}
CMD:mirarest(playerid,params[])
{
	new id;
	if(Info[playerid][pAdmin] == 0) return SendClientMessage(playerid,Color_Blanco,"No tienes el nivel necesario para esto");
	if(sscanf(params,"d",id))return SendClientMessage(playerid,Color_Blanco,"Usa /mirarest [ID]");
	if(!IsPlayerConnected(id))return SendClientMessage(playerid,Color_Blanco,"Id Invalida");
	Estadisticas(id);
	return 1;
}
CMD:banear(playerid,params[])
{
	if(Info[playerid][pAdmin] < 8)return SendClientMessage(playerid,Color_Blanco,"No tienes el nivel necesario para esto");
	ShowPlayerDialog(playerid,Dialogo_Ban,DIALOG_STYLE_LIST,"Lista Para Banear","Niño Rata\n Molestando a los otros Usuarios\n Hacking \n Otro","Aceptar","Salir");
	return 1;
}
CMD:darfaccion(playerid,params[])
{
	new id, fac, nf[90],st[150];
	if(Info[playerid][pAdminEF] == 0)return SendClientMessage(playerid,Color_Blanco,"No tienes la asignacion necesiaria para esto");
	if(sscanf(params,"dd",id,fac))return SendClientMessage(playerid,Color_Blanco,"Usa /darfaccion [ID][FaccionID]");
	if(IsPlayerConnected(id))
	{
	    if(fac > MAX_FACCION)return SendClientMessage(playerid,Color_Rojo,"No puedes hacer esto *");
	    else
	    {
	        switch(fac)
	        {
				case 0: format(nf,sizeof(nf),"Ninguna");
				case 1: format(nf,sizeof(nf),"Departamento de policia de Los Santos");
				default: format(nf,sizeof(nf),"BUG FACCION INVALIDA");
			}
			format(st,sizeof(st),"·[Bot Aviso] %s le dio %s a %s",PlayerName(playerid),nf,PlayerName(id));
			AdminMensaje(Color_Blanco,st);
			format(st,sizeof(st),"El administrador %s te asigno la faccion\n%s\nAhora eres lider de dicha faccion",PlayerName(playerid),nf);
			ShowPlayerDialog(id,D_INVALIDDIALOG,DIALOG_STYLE_MSGBOX,"Bot aviso",st,"Aceptar","");
		}
	}
	return 1;
}
CMD:dardinero(playerid,params[])
{
	new st[100],id,d;
	if(Info[playerid][pAdminTech] == 0)return SendClientMessage(playerid,Color_Blanco,"No tienes la asignacion necesaria para esto");
	else
	{
	    if(sscanf(params,"dd",id,d))return SendClientMessage(playerid,Color_Blanco,"Usa /dardinero [ID][Monto]");
	    if(IsPlayerConnected(id))
	    {
	        if(d > 10000000)return SendClientMessage(playerid,-1,"No puedes dar mas de 10 millones");
	        else
			{
			    DarDinero(playerid,d);
			    format(st,sizeof(st),"[Bot Aviso] %s le dio %d de dinero a %s",PlayerName(playerid),d,PlayerName(id));
				AdminMensaje(Color_Blanco,st);
			}
		}
	}
	return 1;
}