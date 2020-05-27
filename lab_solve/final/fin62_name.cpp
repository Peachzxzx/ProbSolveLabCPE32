g
{
	string ins;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin,ins);
	getline(cin,aa);
	int count = 0;
	int strLoop = 0;
	int wwww = ins.size();
	for (int i = 0; i < aa.size(); i++)
	{
		if (aa[i] == ins[strLoop])
			strLoop++;
		if (strLoop == wwww)
			{
				count++;
				strLoop = 0;
			}
	}
	cout << count;
}
