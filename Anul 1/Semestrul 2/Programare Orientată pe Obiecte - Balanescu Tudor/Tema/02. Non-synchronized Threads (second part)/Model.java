public class Model {
    public void increments(int sleeping_time) throws Exception{
	    int temp;
        
        Thread.sleep(sleeping_time);
        temp=x;
        
		Thread.sleep(sleeping_time);
		temp=temp+1;

		Thread.sleep(sleeping_time);
		x=temp;
	}

	public int get_x(){return x;}
	private int x=0;
}