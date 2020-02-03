#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<io.h>
using namespace std;
#include"JF.hpp"
#include"password.hpp"

#define MAPX ((classic_mode)?(52):((teacher_mode)?81:0))
#define MAPY ((classic_mode)?(17):((teacher_mode)?17:0))
#define CLEAR system("cls");gotoxy(0,0)

struct pos;
struct _user;
void login();
void regis();
void _save();
void gotoxy(int x,int y);
void student_init();
void player_init();
void teacher_init();
void map_init();
void init();
void game_init();
void _map();
void start_classic();
void start_teacher();
void JC(string s);
void JC_the_teacher();
int mymin(int x,int y);
int do_menu(int id);
void getSubdirs(std::string path,vector<string>&files);
void hide_cursor();
void show_cursor();
void color(const unsigned short color1);

int d_x[]={0,0,-1,1};
int d_y[]={-1,1,0,0};
vector<string>users;
vector<string>menu[100];
//bool go_back;
bool classic_mode;
bool teacher_mode;
bool have_JCed_the_teacher=0; 
/*
up,down,left,right.
*/

struct pos {int x,y;pos(int xx=0,int yy=0) {x=xx;y=yy;}};
struct _user {
	string name;
	string password;
	int ostrakon;
	int memory1[90];
	string memory2[10];
	_user(string name2="",string password2="",int ost2=0) {
		name=name2;
		password=password2;
		ostrakon=ost2;
	}
	void update(int memory3[90],string memory4[10]) {
		for(int i=0;i<90;i++) memory1[i]=memory3[i];
		for(int i=0;i<10;i++) memory2[i]=memory4[i];
	}
};
string name_pos[110][110];

class student {
private:
	int x,y,id;
	bool gotowc;
	bool backwc;
	int hide;
	string name;
	vector<pos>s;
	//int posmin[20][60]; 
	bool check(int x,int y) {
		if(x==0||y==0) return false;
		if(x>=52||y>=17) return false;
		if(mapnow[y][x]!=' ') return false;
		return true;
	}
public:
	int count;
	student(int x2=0,int y2=0,int id2=0,string name2="") {x=x2;y=y2;id=id2;name=name2;hide=0;gotowc=false;}
	
	string getname() {return name;}
	void myinit() {
		s.push_back(pos(x,y));
	}
	void print(char c) {
		mapnow[y][x]=c;
		//gotoxy(x,y);
		//cout<<c;
	}
	void move() {
		if(classic_mode) {
			int d=cyrand(0,3);
			int xx=x+d_x[d];
			int yy=y+d_y[d];
			if(check(xx,yy)) {
				print(' ');
				x=xx;
				y=yy;
				print('o');
				s.push_back(pos(x,y));
				//posmin[y][x]=mymin(posmin[y][x],s.size()-1);
			} else {
				int d=cyrand(0,3);
				int xx=x+d_x[d];
				int yy=y+d_y[d];
				if(check(xx,yy)) {
					print(' ');
					x=xx;
					y=yy;
					print('o');
					s.push_back(pos(x,y));
					//posmin[y][x]=mymin(posmin[y][x],s.size()-1);
				}
			}
		} else {
			if(teacher_mode) {
				if(hide) {
					hide--;
				} else {
					if(gotowc) {
						if(on_the_seat()) {
							int xx=x;
							int yy=y+1;
							if(check(xx,yy)) {
								print(' ');
								x=xx;
								y=yy;
								print('o');
								s.push_back(pos(x,y));
								//posmin[y][x]=mymin(posmin[y][x],s.size()-1);
							}
						} else {
							if(mapnow[y][x+1]!='_'&&mapnow[y][x+1]!='*'&&mapnow[y-1][x]!='*'&&mapnow[y][x+1]!='|'&&mapnow[y-1][x+1]!='_') {
								int xx=x+1;
								int yy=y;
								if(check(xx,yy)) {
									print(' ');
									x=xx;
									y=yy;
									print('o');
									s.push_back(pos(x,y));
									//posmin[y][x]=mymin(posmin[y][x],s.size()-1);
								}
							} else {
								if(mapnow[y][x+1]=='_'||mapnow[y][x+1]=='|'||mapnow[y-1][x+1]=='_') {
									int xx=x;
									int yy=y-1;
									if(check(xx,yy)) {
										print(' ');
										x=xx;
										y=yy;
										print('o');
										s.push_back(pos(x,y));
										//posmin[y][x]=mymin(posmin[y][x],s.size()-1);
									}
								} else {
									if(mapnow[y][x+1]=='*') {
										hide=10;
										print(' ');
										gotowc=0;
										backwc=1;
									} else {
										if(mapnow[y-1][x]=='*') {
											hide=10;
											print(' ');
											gotowc=0;
											backwc=1;
										}
									}
								}
							}
						}
						
					} else {
						if(backwc) {
							go_back();
							if(x==s[0].x&&y==s[0].y) backwc=false;
						}
					}
				}
			}
		}
	}
		
	void go_back() {
		if(s.size()==1) return;
		print(' ');
		x=s[s.size()-2].x;
		y=s[s.size()-2].y;
		print('o');
		s.pop_back();
	}
	
	void WC() {
		gotowc=1;
	}
	
	bool on_the_seat() {
		return (x==s[0].x&&y==s[0].y);
	}
	
	bool check2() {
		return gotowc||backwc;
	}
};

class player {
private:
	int x;
	int y;
	bool check(int x,int y) {
		if(x==0||y==0) return false;
		if(x>=MAPX||y>=MAPY) return false;
		if(mapnow[y][x]!=' ') return false;
		return true;
	}
public:
	player(int xx=0,int yy=0) {x=xx;y=yy;}
	int getx() {return x;}
	int gety() {return y;}
	bool check2() {
		if(mapnow[y-1][x]=='+') return true;
		return false;
	}
	bool check3() {
		if(mapnow[y+1][x]=='*') return true;
		return false;
	}
	void print(char c) {
		mapnow[y][x]=c;
		//gotoxy(x,y);
		//cout<<c;
	}
	void move(int d) {
		//cout<<x<<" "<<y<<endl;
		int xx=x+d_x[d];
		int yy=y+d_y[d];
		if(check(xx,yy)) {
			print(' ');
			x=xx;
			y=yy;
			print('x');
		}
	}
};
_user user;

class teacher {
private:
	int x,y;
	bool go;
	bool back;
	int stay;
	int flag;
	vector<pos>s;
	void print(char c) {
		mapnow[y][x]=c;
	}
public:
	int count;
	teacher(int x2=0,int y2=0) {x=x2,y=y2;s.push_back(pos(x,y));print('O');stay=0;}
	void go_back() {
		if(s.size()==1) return;
		print(' ');
		x=s[s.size()-2].x;
		y=s[s.size()-2].y;
		print('O');
		s.pop_back();
	}
	bool on_the_seat() {return (x==s[0].x&&y==s[0].y);}
	bool check() {return 1;}
	void coffee_time() {go=1;flag=0;stay=0;}
	void move() {
		if(stay>0) {
			stay--;
		} else {
			if(go) {
				if(flag==0) {
					if(x==38) {
						flag=1;
						print(' ');
						y++;
						print('O');
						s.push_back(pos(x,y));
					} else {
						print(' ');
						x++;
						print('O');
						s.push_back(pos(x,y));
					}
				} else {
					if(flag==1) {
						if(x==72) {
							flag=2;
							print(' ');
							y++;
							print('O');
							s.push_back(pos(x,y));
						} else {
							print(' ');
							x++;
							print('O');
							s.push_back(pos(x,y));
						}
					} else {
						if(flag==2) {
							if(y==5) {
								go=0;
								back=1;
								if(user.memory1[0]>0) {
									user.memory1[0]--;
									stay=30;
								} stay=10;
							} else {
								print(' ');
								y++;
								print('O');
								s.push_back(pos(x,y));
							}
						}
					}
				}
			} else {
				if(back) {
					if(on_the_seat()) {
						back=0;
					} else {
						go_back();
					}
				}
			}
		}
	}
};

student st[18];
player jcer;
teacher tc;



int main() {
	init();
	
	login();
menu1:
	CLEAR;
	//user.ostrakon=19260817;
	int now=do_menu(1);
	if(now==1) {
menu2:
		int now2=do_menu(2);
		if(now2==1) {
			classic_mode=1;
			start_classic();
			classic_mode=0;
			goto menu2;
		} else {
			if(now2==2)  {
				teacher_mode=1;
				start_teacher();
				teacher_mode=0;
				goto menu2;
			} else {
				if(now2==3) {
					goto menu1;
				} else {
					goto menu2;
				}
			}
		}
	} else {
		if(now==2) {
menu3:
			CLEAR;
			gotoxy(0,0);
			cout<<"Ostrakon : "<<user.ostrakon;
			int now2=do_menu(3);
			if(now2==1) {
				if(user.ostrakon>=50) {
					user.memory1[0]++;
				} else {
					CLEAR;
					cout<<"Your Ostrakon Isn't Enough!";
					goto menu3;
				}
			} else {
				if(now2==2) {
					goto menu1;
				} else {
					goto menu3;
				}
			}
		} else {
			if(now==3) {
				CLEAR;
				cout<<"My ostrakons : "<<user.ostrakon<<endl;
				cout<<"The fastest JFCA : "<<user.memory1[0]<<"ms"<<endl;
				Sleep(100);
				char c=0;
				while(c==0) c=getch();
				goto menu1; 
			} else {
				if(now==4) {
					_save();
					goto menu1;
				} else {
					if(now==5) {
						exit(0);
					} else {
						goto menu1;
					}
				}
			}
		}
	}
	return 0;
}

void regis() {
_register:
	system("cls");
	string username="";
	cout<<"请输入用户名:"<<endl;
	cin>>username;
	bool find=0;
	for(int i=0;i<users.size();i++) {
		if(users[i]==username) {
			find=1;
			break;
		}
	}
	if(find) {
		cout<<"该用户名已存在,请重新注册.";
		Sleep(2000);
		system("cls");
		gotoxy(0,0);
		goto _register;
	}
	string password1="";
	cout<<"请输入密码:"<<endl;
	cin>>password1;
	string password2="";
	cout<<"请重复密码:"<<endl;
	cin>>password2;
	if(password1!=password2) {
		cout<<"两次密码不一致,请重新注册.";
		Sleep(2000);
		system("cls");
		gotoxy(0,0);
		goto _register;
	}
	cout<<"注册成功!"<<endl;
	string cmd="mkdir save\\"+username;
	system(cmd.c_str());
	string _path = "save\\"+username+"\\info.txt";
	ofstream fout(_path.c_str());
	fout.close();
	string path="save\\"+username+"\\info.txt";
	freopen(path.c_str(),"w",stdout);
	int key=cyrand(1,100);
	cout<<key<<" ";
	cout<<encry(password1,key)<<" ";
	cout<<encry("0",key)<<" ";
	for(int i=0;i<=79;i++) cout<<encry("0",key)<<" ";
	for(int i=80;i<=98;i++) cout<<encry("NULL",key)<<" ";
	cout<<encry("NULL",key);
	freopen("CON","w",stdout);
	cout<<"请重新登陆.";
	exit(0);
}

void login() {
	char c;
	freopen("CON","r",stdin);
	system("cls");
	gotoxy(0,0);
keyin_username:
	cout<<"请输入用户名:\n(若未注册,输入register来注册)"<<endl;
	string username="";
	cin>>username;
	if(username=="register") {
		regis();
		return;
	}
	bool find=0;
	for(int i=0;i<users.size();i++) {
		if(users[i]==username) {
			find=1;
			break;
		}
	}
	if(!find) {
		cout<<"未找到此用户.";
		c=0;
		while(c==0) c=getch();
		system("cls");
		gotoxy(0,0);
		goto keyin_username;
	}
	
	int key=0;
	string password="";
	string ostrakon_s="";
	int ostrakon=0;
	
	string path="save\\"+username+"\\info.txt";
	char passwordc[10010];
	char ostrakon_sc[10010];
	char memory3_sc[90][10010];
	char memory4c[10][10010];
	string memory3_s[90];
	string memory4[90];
	int memory3[90];
	FILE *fin = NULL;
	fin=fopen(path.c_str(),"rb");
	fscanf(fin,"%d %s %s",&key,&passwordc,&ostrakon_sc);
	for(int i=0;i<90;i++) fscanf(fin,"%s",&memory3_sc[i]);
	for(int i=0;i<10;i++) fscanf(fin,"%s",&memory4c[i]);
	fclose(fin);
	password=passwordc;
	ostrakon_s=ostrakon_sc;
	for(int i=0;i<90;i++) memory3_s[i]=memory3_sc[i];
	for(int i=0;i<10;i++) memory4[i]=memory4c[i];
	
	password=decry(password,key);
	ostrakon_s=decry(ostrakon_s,key);
	
	for(int i=0;i<90;i++) memory3_s[i]=decry(memory3_s[i],key);
	for(int i=0;i<10;i++) memory4[i]=decry(memory4[i],key);
	
	stringstream ss;
	ss<<ostrakon_s;
	ss>>ostrakon;
	for(int i=0;i<90;i++) {
		ss<<memory3_s[i];
		ss>>memory3[i];
	}
	cout<<"请输入密码:"<<endl;
	string passin;
	cin>>passin;
	if(passin==password) {
		cout<<"登陆成功!";
		user=_user(username,passin,ostrakon);
		user.update(memory3,memory4);
		c=0;
		while(c==0) c=getch();
		return;
	} else {
		cout<<"密码错误,请重新登陆.";
		system("cls");
		gotoxy(0,0);
		goto keyin_username;
	}
	
}

void _save() {
	CLEAR;
	string path="save\\"+user.name+"\\info.txt";
	FILE *fout = NULL;
	fout=fopen(path.c_str(),"w");
	int key=cyrand(1,100);
	string ostrakon_s;
	stringstream ss;
	ss<<user.ostrakon;   
	ss>>ostrakon_s;
	fprintf(fout,"%d %s %s ",key,encry(user.password,key).c_str(),encry(ostrakon_s,key).c_str());
	for(int i=0;i<=89;i++) {
		string memory1_s;
		ss<<user.memory1[i];
		ss>>memory1_s;
		fprintf(fout,"%s ",encry(memory1_s,key).c_str());
	}
	for(int i=0;i<=8;i++)
		fprintf(fout,"%s ",encry(user.memory2[i],key).c_str());
	fprintf(fout,"%s",encry(user.memory2[9],key).c_str());
	fclose(fout);
	CLEAR;
}

void gotoxy(int x,int y) {CONSOLE_SCREEN_BUFFER_INFO csbiInfo;HANDLE hConsoleOut;hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);csbiInfo.dwCursorPosition.X = x;csbiInfo.dwCursorPosition.Y = y;SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);}

void student_init() {
	for(int i=1;i<=17;i++) {
		string namenow=names[cyrand(0,(sizeof(names)/sizeof(names[0]))-1)];
		int x=((i-1)%6+1)*8-4;
		int y=7+((i-1)/6)*4;
		st[i]=student(x,y,i,namenow);
		name_pos[y][x]=namenow;
		st[i].myinit();
		/*
		s[i].id=i;
		s[i].x=((i-1)%6+1)*8-4;
		s[i].y=7+((i-1)/6)*4;
		*/
	}
}

void player_init() {
	jcer=player(44,15);
}

void teacher_init() {
	tc.count=0;
	tc=teacher(24,1);
}

void map_init() {
	if(classic_mode) {
		for(int i=0;i<=MAPY-1;i++) {
			mapnow[i]=classic_map[i];
		}
	} else {
		if(teacher_mode) {
			for(int i=0;i<=MAPY-1;i++) {
				mapnow[i]=teacher_map[i];
			}
		}
	}
}

void init() {
	student_init();
	player_init();
	getSubdirs("save",users);
	
	menu[1].push_back("Empty");
	menu[1].push_back("1.Start");
	menu[1].push_back("2.Shop");
	menu[1].push_back("3.Bag");
	menu[1].push_back("4.Save");
	menu[1].push_back("5.Exit");
	
	menu[2].push_back("Empty");
	menu[2].push_back("1.Classic Mode");
	menu[2].push_back("2.Teacher Mode");
	menu[2].push_back("3.Back");
	
	menu[3].push_back("Empty");
	menu[3].push_back("1.Cappuccino - 50");
	menu[3].push_back("2.Back");
}

void game_init() {
	student_init();
	player_init();
}

void _map() {
	gotoxy(0,0);
	for(int i=0;i<=MAPY-1;i++) {
		cout<<mapnow[i]<<endl;
	}
}

void start_classic() {
	map_init();
	hide_cursor();
	game_init();
	//int cnt=0;
	while(1) {
		_map();
		//cnt++;
		//for(int i=1;i<=17;i++) st[i].go_back();
		/*
		if(go_back) {
			Sleep(100);
			for(int i=1;i<=17;i++) {
				st[i].go_back();
			}
		} else */{
			for(int i=1;i<=17;i++) {
				if(cyrand(0,99)==0) st[i].move();
			}
		}
		
	    if (!_kbhit()) {
	    	
		} else {
	    	char c=getch();
	    	if(jcer.getx()==44&&jcer.gety()==15&&c=='w') {
				int x=0,y=0;
				char c=0;
				system("cls");
				gotoxy(x,y);
				cout<<jc10;
				Sleep(100);
				while(c==0) c=getch();
			} else if(jcer.check2()&&c=='w') {
				JC(name_pos[jcer.gety()][jcer.getx()]);
			} else {
				if(jcer.getx()==50&&c=='d') {
					break;
				}
			}
	    	switch(c)
	    	{
	    	case 'w':
	    		jcer.move(0);
	    		break;
	    	case 's':
	    		jcer.move(1);
	    		break;
	    	case 'a':
	    		jcer.move(2);
	    		break;
	    	case 'd':
	    		jcer.move(3);
	    		break;
	    	/*
	    	case 'e':
	    		go_back=1;
	    		break;
	    	case 'r':
	    		go_back=0;
	    		break;
	    	*/
			}
		}
	}
	show_cursor();
}

void start_teacher() {
	map_init();
	hide_cursor();
	game_init();
	teacher_init();
	while(1) {
		_map();
		
		for(int i=1;i<=17;i++) {
			if(cyrand(0,9999)==0&&st[i].on_the_seat()) st[i].WC();
		}
		
		for(int i=1;i<=17;i++) {
			if(st[i].count==30) {
				st[i].count=0;
				st[i].move();
			} else {
				if(st[i].check2()) st[i].count++;
			}
		}
		
		if(cyrand(0,999)==0&&tc.on_the_seat()) {
			tc.coffee_time();
		}
		
		
		
		if(tc.count>=50) {
			tc.count=0;
			tc.move();
		} else tc.count++;
		
	    if (!_kbhit()) {
	    	
		} else {
	    	char c=getch();
	    	if(jcer.getx()==44&&jcer.gety()==15&&c=='w') {
				int x=0,y=0;
				char c=0;
				system("cls");
				gotoxy(x,y);
				cout<<jc10;
				Sleep(100);
				while(c==0) c=getch();
			} else if(jcer.check2()&&c=='w') {
				JC(name_pos[jcer.gety()][jcer.getx()]);
			} else if(jcer.check3()&&c=='s'&&have_JCed_the_teacher==0) {
				JC_the_teacher();
			}  else {
				if(jcer.getx()==50&&c=='d') {
					break;
				}
			}
	    	switch(c)
	    	{
	    	case 'w':
	    		jcer.move(0);
	    		break;
	    	case 's':
	    		jcer.move(1);
	    		break;
	    	case 'a':
	    		jcer.move(2);
	    		break;
	    	case 'd':
	    		jcer.move(3);
	    		break;
	    	/*
	    	case 'e':
	    		go_back=1;
	    		break;
	    	case 'r':
	    		go_back=0;
	    		break;
	    	*/
			}
		}
	}
	show_cursor();
}

int time_end;

void update_clock(int beg,int x,int y) {
	gotoxy(x,y-1);
	time_end=clock()-beg;
	cout<<"Time : "<<time_end<<"ms";
}

void JC(string s) {
	int beg=clock();
	int x=1,y=1;
	char c;
	system("cls");
	gotoxy(x,y);
	cout<<jc0;
	
	while(c!='I') {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc1;
	
	while(c!=' ') {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc2;
	
	while(c!='A') {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc3;
	
	while(c!='K') {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc4;
	
	while(c!=' ') {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc5;
	
	while(c!='I') {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc6;
	
	while(c!='O') {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc7;
	
	while(c!='I') {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc8;
	
	while(c!=13) {
		if(!_kbhit()) {
			update_clock(beg,x,y);
		} else c=getch();
	}
	gotoxy(x,y);
	cout<<jc9;
	
	gotoxy(x+13,y+3);
	cout<<s;
	
	c=0;
	while(c==0) c=getch();
	user.ostrakon++;
	if(user.memory1[0]==0) {
		user.memory1[0]=time_end;
	} else {
		if(time_end<user.memory1[0]) {
			user.ostrakon+=2;
			user.memory1[0]=time_end;
		}
	}
}

void JC_the_teacher() {
	have_JCed_the_teacher=true;
	system("cls");
	gotoxy(0,0);
	cout<<jc11;
	gotoxy(1,4);
	int nowx=2,x2=1;
	int nowy=4,y2=0;
	int begin_time=clock();
	gotoxy(nowx,nowy);
	color(6);
	cout<<'o';
	color(7);
	while(clock()-begin_time<=10000) {
		gotoxy(1,2);
		cout<<"time : "<<clock()-begin_time<<"ms";
		gotoxy(nowx,nowy);
		if(!kbhit()) {
			
		} else {
			char c=getch();
			if(c==224) {
				switch(getch()){
			    case 72:
			        if(nowy!=4) {
			        	y2--;
			        	color(7);
						gotoxy(nowx,nowy);
						cout<<'o';
						nowy-=2;
						color(6);
						gotoxy(nowx,nowy);
						cout<<'o';
						color(7);
					}
			        break;
				case 80:
			      	if(nowy!=8) {
			      		y2++;
			        	color(7);
						gotoxy(nowx,nowy);
						cout<<'o';
						nowy+=2;
						color(6);
						gotoxy(nowx,nowy);
						cout<<'o';
						color(7);
					}
			        break;
			    case 75:
			    	if(nowx!=2) {
			    		x2--;
			        	color(7);
						gotoxy(nowx,nowy);
						cout<<'o';
						nowx-=3;
						color(6);
						gotoxy(nowx,nowy);
						cout<<'o';
						color(7);
					}
					break;
			    case 77:
			        if(nowx!=17) {
			        	x2++;
			        	color(7);
						gotoxy(nowx,nowy);
						cout<<'o';
						nowx+=3;
						color(6);
						gotoxy(nowx,nowy);
						cout<<'o';
						color(7);
					}
					break;
			    }
			} else {
				switch(c){
			    case 'w':
			        if(nowy!=4) {
			        	y2--;
			        	color(7);
						gotoxy(nowx,nowy);
						cout<<'o';
						nowy-=2;
						color(6);
						gotoxy(nowx,nowy);
						cout<<'o';
						color(7);
					}
			        break;
				case 's':
			      	if(nowy!=8) {
			      		y2++;
			        	color(7);
						gotoxy(nowx,nowy);
						cout<<'o';
						nowy+=2;
						color(6);
						gotoxy(nowx,nowy);
						cout<<'o';
						color(7);
					}
			        break;
			    case 'a':
			    	if(nowx!=2) {
			    		x2--;
			        	color(7);
						gotoxy(nowx,nowy);
						cout<<'o';
						nowx-=3;
						color(6);
						gotoxy(nowx,nowy);
						cout<<'o';
						color(7);
					}
					break;
			    case 'd':
			        if(nowx!=17) {
			        	x2++;
			        	color(7);
						gotoxy(nowx,nowy);
						cout<<'o';
						nowx+=3;
						color(6);
						gotoxy(nowx,nowy);
						cout<<'o';
						color(7);
					}
					break;
			    case 13:
			    	int JC_begin=clock();
			    	if(y2*6+x2==18) {
			    		CLEAR;
			    		gotoxy(0,0);
			    		cout<<jc10;
			    		char pr=0;
			    		while(pr==0) pr=getch();
					} else JC(st[y2*6+x2].getname());
					int JC_end=clock();
					begin_time+=JC_end-JC_begin;
					CLEAR;
					cout<<jc11;
					gotoxy(nowx,nowy);
					color(6);
					cout<<"o";
					color(7);
			    	break;
			    }
			}
		}
		
	}
}

int mymin(int x,int y) {return x<y?x:y;}

int do_menu(int id) {
	CLEAR;
	for(int i=1;i<=menu[id].size()-1;i++) {
		gotoxy(1,i);
		cout<<menu[id][i]<<endl;
	}
	int pr=233,now=1;
	color(6);
	gotoxy(1,now);
	cout<<menu[id][now];
	color(7);
	while(pr!=13) {
		pr=getch();
		if(pr==224) {
			switch(getch()){
		        case 72:
		        	color(7);
					gotoxy(1,now);
					cout<<menu[id][now];
					if(now==1) {
						now=menu[id].size()-1;
					} else {
						now--;
					}
					color(6);
					gotoxy(1,now);
					cout<<menu[id][now];
					color(7);
		           break;
		        case 80:
					color(7);
					gotoxy(1,now);
					cout<<menu[id][now];
					if(now==menu[id].size()-1) {
						now=1;
					} else {
						now++;
					}
					color(6);
					gotoxy(1,now);
					cout<<menu[id][now];
					color(7);
		            break; 
		     }
		} else {
			if(pr=='s') {
				color(7);
				gotoxy(1,now);
				cout<<menu[id][now];
				if(now==menu[id].size()-1) {
					now=1;
				} else {
					now++;
				}
				color(6);
				gotoxy(1,now);
				cout<<menu[id][now];
				color(7);
			}
			if(pr=='w') {
				color(7);
				gotoxy(1,now);
				cout<<menu[id][now];
				if(now==1) {
					now=menu[id].size()-1;
				} else {
					now--;
				}
				color(6);
				gotoxy(1,now);
				cout<<menu[id][now];
				color(7);
			}
		}
	}
	return now;
}

void getSubdirs(std::string path,vector<string>&files) {
	long long hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1) {
		do {
			if((fileinfo.attrib && _A_SUBDIR))
				if(strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					files.push_back(fileinfo.name);
		} while (_findnext(hFile, &fileinfo) == 0);_findclose(hFile);
	}
}

void hide_cursor() {
	HANDLE h_GAME =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME,&cursor_info);
	cursor_info.bVisible=false;
	SetConsoleCursorInfo(h_GAME,&cursor_info);
}

void show_cursor() {
	HANDLE h_GAME =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME,&cursor_info);
	cursor_info.bVisible=true;
	SetConsoleCursorInfo(h_GAME,&cursor_info);
}



void color(const unsigned short color1) {
	/*颜色对应值：
	　　0=黑色              8=灰色　　
	　 1=蓝色                9=淡蓝色               　　
	　　2=绿色              10=淡绿色     0xa      　　
	　　3=湖蓝色       11=淡浅绿色       0xb　
	　　4=红色              12=淡红色      0xc　　
	　　5=紫色              13=淡紫色      0xd     　　
	　　6=黄色              14=淡黄色      0xe     　　
	　　7=白色              15=亮白色      0xf
	　　也可以把这些值设置成常量。
	*/
	if(color1>=0&&color1<=15) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	} else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}
