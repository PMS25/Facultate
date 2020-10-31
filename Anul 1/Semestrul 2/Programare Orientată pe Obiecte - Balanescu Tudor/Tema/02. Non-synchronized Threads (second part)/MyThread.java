public class MyThread extends Thread{
	public MyThread(Model m, int st){
		md=m;
		sleep_time=st;
	}

	public void run(){
        try{
			md.increments(sleep_time);
		}catch(Exception e){}
	}

	private Model md;
	int sleep_time=0;
}