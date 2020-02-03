string encry1(string s,int key) {
	string ret="";
	for(int i=0;i<s.size();i++) {
		ret+=s[i]+key*2;
	}
	return ret;
}

string decry1(string s,int key) {
	string ret="";
	for(int i=0;i<s.size();i++) {
		ret+=s[i]-key*2;
	}
	return ret;
}

string encry2(char c) {
	string ret="";
	int a=((int)c)/26;
	int b=((int)c)%26;
	ret+=(char)(a+'a');
	ret+=(char)(b+'a');
	return ret;
}

char decry2(string s) {
	char ret=0;
	int a=s[0]-'a';
	int b=s[1]-'a';
	ret=a*26+b;
	return ret;
}

string encry3(string s,int key) {
	string s1=encry1(s,key);
	string s2="";
	for(int i=0;i<s1.size();i++) s2+=encry2(s1[i]);
	return s2;
}

string decry3(string s,int key) {
	string s1="",tmp="";
	for(int i=0;i<s.size();i+=2) {
		tmp="";
		tmp+=s[i];
		tmp+=s[i+1];
		s1+=decry2(tmp);
	}
	string s2=decry1(s1,key);
	return s2;
}

string encry(string s,int key) {
	return encry3(encry3(s,key),key);
}

string decry(string s,int key) {
	return decry3(decry3(s,key),key);
}
