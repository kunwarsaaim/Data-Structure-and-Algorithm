#include<graphics.h>
#include<cmath>
#include<conio.h>
int main(){
    float angle_earth=0,theta,th,angle_moon,theta2;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    
    while(!kbhit()){
        
        
        
        for(angle_earth=0,angle_moon=0;angle_earth<=360,angle_moon<=360;angle_earth++){
            
            theta=M_PI*angle_earth/180;
            theta2=M_PI*angle_moon/180;
            //thetaLine=M_PI*angleLine/180;
            //earth orbit
            
            ellipse(650,350,0,360,400,150);
            
            //sun
            
            setfillstyle(SOLID_FILL,YELLOW);
            setcolor(YELLOW);
            circle(650,350,50);
            floodfill(650,350,YELLOW);
            
            //earth
            setfillstyle(SOLID_FILL,BLUE);
            setcolor(BLUE);
            circle(650+400*cos(theta),350-150*sin(theta),25);
            floodfill(650+400*cos(theta),350-150*sin(theta),BLUE);
            //floodfill(1048,350,BLUE);
            
            //earth axis
            setcolor(DARKGRAY);
            
            //line(650+400*cos(theta)-50*cos(thetaLine),350-150*sin(theta)+50*sin(thetaLine),650+400*cos(theta)+50*cos(thetaLine),350-150*sin(theta)-50*sin(thetaLine));
            th=75*M_PI/180;
            line(650+400*cos(theta)-50*cos(th),350-150*sin(theta)+50*sin(th),650+400*cos(theta)+50*cos(th),350-150*sin(theta)-50*sin(th));
            //moon orbit
            setcolor(WHITE);
            ellipse(650+400*cos(theta),350-150*sin(theta),0,360,80,50);
            
            //moon
            
            setfillstyle(SOLID_FILL,DARKGRAY);
            setcolor(DARKGRAY);
            circle(650+400*cos(theta)+80*cos(theta2),350-150*sin(theta)-50*sin(theta2),15);
            floodfill(650+400*cos(theta)+80*cos(theta2),350-150*sin(theta)-50*sin(theta2),DARKGRAY);
            //floodfill(1128,350,DARKGRAY);650+400*cos(theta)+80*cos(theta2),
            
            //moon axis
            //th=60*M_PI/180;
            //line(650+400*cos(theta)+80*cos(theta2)-30*cos(th),350-150*sin(theta)-50*sin(theta2)+30*sin(th),650+400*cos(theta)+80*cos(theta2)+30*cos(th),350-150*sin(theta)-50*sin(theta2)-30*sin(th));
            
            if(angle_earth==0){
                outtextxy(50,50,"press any key to start animation");
                getch();
            }
            outtextxy(50,60,"press any key to finish it");
            if(angle_earth==360)
                angle_earth=0;
            
            
            
            if(angle_moon==360)
                angle_moon=0;
            
            
            
            
            
            
            angle_moon=angle_moon+3;
            
            
            delay(50);
            cleardevice();
            
        }
        
        
    }
    
    getch();
    closegraph();
    return 0;
}

