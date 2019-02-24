funcion PasarTime()
{
	if(paydayl <= 59)
	{
	    paydayl ++;
	}
	else
	{
		Payday();
	}
	return 1;
}
funcion Payday()
{
	for(new i;i<MAX_PLAYERS;i++)
	{
	    new lot = random(250);
	    paydayl = 0;
	    new str[1000],st[100];
	    new p[50];
	    new hayga;
	    if(IsPlayerConnected(i))
	    {
			if(Info[i][pLot] >= 1)
			{
			    format(st,sizeof(st),"===============================\n");
			    strcat(str,st,sizeof(str));
			    format(st,sizeof(st),"Loteria diaria: numero ganador %d",lot);
			    strcat(str,st,sizeof(str));
			    if(Info[i][pLot] == lot)
		        {
		            format(p,sizeof(p),"%s",PlayerName(i));
		            hayga = 1;
				}
				if(hayga == 0)format(p,sizeof(p),"Nadie");
			    format(st,sizeof(st),"Ganador es: %s",p);
			    strcat(str,st,sizeof(str));
			    format(st,sizeof(st),"===============================\n");
			    strcat(str,st,sizeof(str));
			    ShowPlayerDialog(i,D_LOTERIA,DIALOG_STYLE_MSGBOX,"Loteria diaria",str,"Aceptar","");
			}
	        if(Info[i][pFac] == 1)
	        {
				switch(Info[i][pRang])
				{
				    case 1:paga[i] = 2500;
				    case 2:paga[i] = 5000;
				    case 3:paga[i] = 7500;
				    case 4:paga[i] = 10000;
				    case 5:paga[i] = 12500;
				    case 6:paga[i] = 15000;
				}
				SendClientMessage(i,0x63FFFFFF,"Anda a cobrar tu paga al ayuntamiento");
			}
			new pastn = levelexp*Info[i][pLevel];
	        if(Info[i][pLevelExp] >= pastn)
	        {
	            SendClientMessage(i,0x63FFFFFF,"Puedes pasar de nivel usa /subirnivel");
			}
	        Info[i][pLevelExp] ++;
		}
	}
	return 1;
}