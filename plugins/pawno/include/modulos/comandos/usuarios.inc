CMD:ayuda(playerid,params[]){return ShowPlayerDialog(playerid,Dialogo_Ayuda,DIALOG_STYLE_LIST,"Lista de Ayuda y / o comandos","General\nFaccion\nRol","Aceptar","Salir");}
CMD:est(playerid,params[]){return Estadisticas(playerid);}
CMD:subirnivel(playerid,params[])
{
	new st[100];
	new pastn = levelexp*Info[playerid][pLevel];
	if(Info[playerid][pLevelExp] >= pastn)
	{
	    ShowPlayerDialog(playerid,D_PASARNIVEL,DIALOG_STYLE_MSGBOX,"Subir Nivel","Puedes pasar de nivel\n¿Quieres hacerlo?","Subir Nivel","Salir");
	}
	else
	{
		format(st,sizeof(st),"te hace falta %d/%d para pasar al nivel %d",pastn,Info[playerid][pLevelExp],Info[playerid][pLevel]+1);
		SendClientMessage(playerid,Color_Blanco,st);
	}
	return 1;
}
/* Comandos OOC */
CMD:duda(playerid,params[])
{return 1;}
CMD:reportar(playerid,params[])
{return 1;}
CMD:b(playerid,params[])
{
	new text[250];
	new string[250],Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name)); if(sscanf(params,"s[250]",text))return SendClientMessage(playerid,Color_Blanco,"Usa /b [Texto - Recuerda que este canal es OOC]");
	format(string,sizeof(string),"[OOC]((%s [%d] [TextoOOC]:%s))",Name,playerid,text); ProxDetector(15, playerid, string,ColorH,ColorH,ColorH2,ColorH3,ColorH4);
	return 1;
}
/* Comandos Rol IC*/
CMD:me(playerid,params[])
{
	new text[250];
	new string[250],Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name));
	if(sscanf(params,"s[250]",text))return SendClientMessage(playerid,Color_Blanco,"Usa /me [Roleo]"); format(string,sizeof(string),"((%s :%s))",Name,text); ProxDetector(15, playerid, string,COLOR_ME,COLOR_ME,COLOR_ME,COLOR_ME,COLOR_ME);
	return 1;
}
CMD:do(playerid,params[])
{
	new text[250];
	new string[250],Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name)); if(sscanf(params,"s[250]",text))return SendClientMessage(playerid,Color_Blanco,"Usa /do [Pensamiento]");
	format(string,sizeof(string),"((%s [Pensamiento]:%s))",Name,text); ProxDetector(15, playerid, string,COLOR_ME,COLOR_ME,COLOR_ME,COLOR_ME,COLOR_ME);
	return 1;
}
CMD:so(playerid,params[])
{
	new text[250];
	new string[250],Name[MAX_PLAYER_NAME];GetPlayerName(playerid,Name,sizeof(Name)); if(sscanf(params,"s[250]",text))return SendClientMessage(playerid,Color_Blanco,"Usa /so [Sonido]");
	format(string,sizeof(string),"((%s [sonido]:Escucha %s))",Name,text); ProxDetector(15, playerid, string,COLOR_ME,COLOR_ME,COLOR_ME,COLOR_ME,COLOR_ME);
	return 1;
}
CMD:g(playerid,params[])
{
 if(Gritando[playerid] == true){Gritando[playerid] = false;}
 else{Gritando[playerid] = true;}
 return 1;
}