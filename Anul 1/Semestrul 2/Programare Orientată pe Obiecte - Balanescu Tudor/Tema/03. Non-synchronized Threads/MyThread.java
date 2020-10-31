public class MyThread extends Thread{
	public MyThread(int i){
		id=i;
	}

	public void run(){
        for(int i=0; i<100; i++)
            System.out.print(id);
    }
    
	int id=0;
}