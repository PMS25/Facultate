public class Main {
    public static void main(String args[]){
		Model mins=new Model();
		MyThread t1, t2;

		int sleeping1 = 21; // modificati acesti timpi si urmariti rezultatele
		int sleeping2 = 1; // alegeti valori apropiate, valori foarte diferite etc. si comentati rezultatele

		t1=new MyThread(mins,sleeping1);
		t2=new MyThread(mins,sleeping2);

		t1.start();t2.start();
		while(t1.isAlive() || t2.isAlive()){}
        
        System.out.println(mins.get_x());
	}
}