funcion AdminMensaje(color,string[])
{
	for(new i;i<MAX_PLAYERS;i++)
	{
		if(IsPlayerConnected(i))
		{
		    if(Info[i][pAdmin] >= 1)
			{
			    SendClientMessage(i,color,string);
			}
			else continue;
		}
		else continue;
	}
	return 1;
}