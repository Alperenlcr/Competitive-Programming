(1000, sizeof(int));
    
    for ( i = 0; i < V; i++)
    {
        cin >> t1 >> t2 >> t3 >> t4;
        k = t3*1000+t4;
        j=0;
        while (vents[k][j] != 0)
            j ++;