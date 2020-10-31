public class Main{
	public static void main(String args[]){
        MyThread t1, t2;
		t1=new MyThread(1);
		t2=new MyThread(2);

		t1.start(); t2.start();
		while(t1.isAlive() || t2.isAlive()){}
	}
}