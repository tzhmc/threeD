#ifndef _EGE_THREED_H_
#define _EGE_THREED_H_
#endif

#ifndef _EGE_H_
#error include "three.h" must after include "ege.h" or "graphics.h"
#endif

double txy=0;
double txz=0;
double tyz=0;
int yl=0,xl=0;
double camerasize;
double xp,yp,zp;
void setcamerasize(int angle){
	if(angle<0||angle>=180){
		return;
	}
	double t=asin(1)*2/(360.0/angle);
	camerasize=1/tan(t);
}
void initwindow(int w,int h,int mod=-1){
	setinitmode(0,0,0);
	initgraph(1,h,0);
	setcaption("3D_camera");
	setcolor(WHITE);
	setfillcolor(WHITE);
	for(int i=4;i<=w;i+=1.0*i/4<1.0*w/40?1.0*i/4:1.0*w/40){
		initgraph(i,h);
		bar(0,0,w,h);
		Sleep(10);
	}
	initgraph(w,h);
	bar(0,0,w,h);
	if(mod==-1){
		for(int i=1;i<=360;i++){
			setcolor(BLACK);
			setfillcolor(BLACK);
			pieslice(w/2,h/2,0,i,100);
			setcolor(WHITE);
			setfillcolor(WHITE);
			pieslice(w/2,h/2,0,360,80);
			Sleep(1);
		}
		setfontbkcolor(WHITE);
		setcolor(BLACK);
		setfont(30,0, "楷体");
		outtextxy(760,280, "ege_3D");
		outtextxy(740,480, "唐子恒制作");
		Sleep(500);
		for(int i=0;i<255;i++){
			setcolor(EGERGB(i,i,i));
			setfillcolor(EGERGB(i,i,i));
			pieslice(w/2,h/2,0,360,i/3+100);
			setcolor(WHITE);
			setfillcolor(WHITE);
			pieslice(w/2,h/2,0,360,80-i/3);
			Sleep(1);
		}
		Sleep(200);
	}
	
}
double angle(double x,double y){
	double res=asin(y/sqrt(x*x+y*y));
	if(x>=0) return res;
	
	else{
		res=asin(1)*2;
		if(y>=0) return res;
		else return -res;
	}
}
void print();
class Point{
	public:
		double x;
		double y;
		double z;
		
    private:
};
void threeD_putline(Point a,Point b){
	//line(800+(t/sqrt(10)*a.x-1.0/sqrt(10)*a.y)*5,500-(1.0/sqrt(10)*a.x+t/sqrt(10)*a.y+1/sqrt(10)*a.z*(0.5+0.5*t))*5,800+(t/sqrt(10)*b.x-1.0/sqrt(10)*b.y)*5,500-(1.0/sqrt(10)*b.x+t/sqrt(10)*b.y+1/sqrt(10)*b.z*(0.5+0.5*t))*5);
	
	a.y=-a.y;
	b.y=-b.y;
	a.x+=xp;
	a.y-=yp;
	a.z+=zp;
	b.x+=xp;
	b.y-=yp;
	b.z+=zp;
	
	double x,y,z;
	x=a.x;
	y=a.y;
	a.x=x*cos(txy)-y*sin(txy);a.y=x*sin(txy)+y*cos(txy);
	x=b.x;
	y=b.y;
	b.x=x*cos(txy)-y*sin(txy);b.y=x*sin(txy)+y*cos(txy);
	
	
	x=a.x;
	z=a.z;
	a.x=x*cos(txz)-z*sin(txz);a.z=x*sin(txz)+z*cos(txz);
	x=b.x;
	z=b.z;
	b.x=x*cos(txz)-z*sin(txz);b.z=x*sin(txz)+z*cos(txz);
	
	y=a.y;
	z=a.z;
	a.y=y*cos(tyz)-z*sin(tyz);a.z=y*sin(tyz)+z*cos(tyz);
	y=b.y;
	z=b.z;
	b.y=y*cos(tyz)-z*sin(tyz);b.z=y*sin(tyz)+z*cos(tyz);
	
	
	if(a.y<=0||b.y<=0) return;
	setlinewidth(1);
	ege_line(a.x/a.y*800*camerasize+800+xl,500-a.z/a.y*800*camerasize+yl,b.x/b.y*800*camerasize+800+xl,500-b.z/b.y*800*camerasize+yl);
}
void threeD_putline(Point a,Point b);


void putline(Point a,Point b){
	//line(800+(t/sqrt(10)*a.x-1.0/sqrt(10)*a.y)*5,500-(1.0/sqrt(10)*a.x+t/sqrt(10)*a.y+1/sqrt(10)*a.z*(0.5+0.5*t))*5,800+(t/sqrt(10)*b.x-1.0/sqrt(10)*b.y)*5,500-(1.0/sqrt(10)*b.x+t/sqrt(10)*b.y+1/sqrt(10)*b.z*(0.5+0.5*t))*5);
	
	a.y=-a.y;
	b.y=-b.y;
	a.x+=xp;
	a.y-=yp;
	a.z+=zp;
	b.x+=xp;
	b.y-=yp;
	b.z+=zp;
	
	double x,y,z;
	x=a.x;
	y=a.y;
	a.x=x*cos(txy)-y*sin(txy);a.y=x*sin(txy)+y*cos(txy);
	x=b.x;
	y=b.y;
	b.x=x*cos(txy)-y*sin(txy);b.y=x*sin(txy)+y*cos(txy);
	
	
	x=a.x;
	z=a.z;
	a.x=x*cos(txz)-z*sin(txz);a.z=x*sin(txz)+z*cos(txz);
	x=b.x;
	z=b.z;
	b.x=x*cos(txz)-z*sin(txz);b.z=x*sin(txz)+z*cos(txz);
	
	y=a.y;
	z=a.z;
	a.y=y*cos(tyz)-z*sin(tyz);a.z=y*sin(tyz)+z*cos(tyz);
	y=b.y;
	z=b.z;
	b.y=y*cos(tyz)-z*sin(tyz);b.z=y*sin(tyz)+z*cos(tyz);
	
	
	if(a.y<=0||b.y<=0) return;
	setlinewidth(1);
	line(a.x/a.y*800*camerasize+800+xl,500-a.z/a.y*800*camerasize+yl,b.x/b.y*800*camerasize+800+xl,500-b.z/b.y*800*camerasize+yl);
}
void putline(Point a,Point b);
void putpoint(Point a,color_t color){
	putpixel(a.x/a.y*800*camerasize+800+xl,500-a.z/a.y*800*camerasize+yl,color);
}
class threeD_object{
	public:
		Point point[2000];
		bool side[4000][2];
		int usepoint;
		std::string name;
    private:
};

void putobj(threeD_object a){
	for(int i=0;i<a.usepoint;i++){
		for(int j=0;j<a.usepoint;j++){
			putline(a.point[i],a.point[j]);
		}
	}
}
void putobj(threeD_object a);

void threeD_putobj(threeD_object a){
	for(int i=0;i<a.usepoint;i++){
		for(int j=i;j<a.usepoint;j++){
			putline(a.point[i],a.point[j]);
		}
	}
}
void threeD_putobj(threeD_object a);

threeD_object getcube(double a,double xp,double yp,double zp){
	threeD_object tmp;
	for(double i=-a;i<=a;i+=a*2){
		for(double j=-a;j<=a;j+=a*2){
			for(double k=-a;k<=a;k+=a*2){
				tmp.point[tmp.usepoint].x=i+xp;
				tmp.point[tmp.usepoint].y=j+yp;
				tmp.point[tmp.usepoint].z=k+zp;
				tmp.usepoint++;
			}
		}
	}
	tmp.name="cube";
	return tmp;
}
threeD_object newpoint(threeD_object a,double x,double y,double z){
	a.point[a.usepoint].x=x;
	a.point[a.usepoint].y=y;
	a.point[a.usepoint].z=z;
	a.usepoint++;
	return a;
}
threeD_object newpoint(threeD_object a,double x,double y,double z);
