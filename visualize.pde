Agent computer=new Agent(0,0,true,false,1.0);
void setup(){
  size(500,500);
  background(0);
}

void draw(){
      computer.res-=0.1;  
  
      println("posx:"+computer.posx);
      println("posy:"+computer.posy);
      
      println("strategy:"+computer.strat);
      println("status:"+computer.status);    
      
      println("resource:"+computer.res);
}


class Agent{
   int posx,posy;
   boolean status;
   boolean strat;
   double res;  
  Agent(int x,int y,boolean _status,boolean _strat,double resource){
        posx=x;
        posy=y;
        res= resource;
        status=_status;
        strat=_strat;             
    }

}