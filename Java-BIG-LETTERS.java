
public class driver {
	//enum letters
	final static int listOfChar[] =
		{10,4536650,12925230,13124108,
		12921164,32010782,32010768,15224366,
		19495506,4329604,2165324,9777481,
		8659215,18732593,18667121,6595878,
		14989576,15259246,14989609,7608366,
		32641156,9741606,18157568,18405034,
		18157905,18157700,32575775};
	static int mat[][];

	static void setMat(int x , int key){
		int bin=16777216;
		x*=5;
		//rebuilding the 5*5 block
		for (int i=0;i<5;i++){
			for (int ii=0;ii<5;ii++){
				if (key < bin)
					mat[x+ii][i]=0;
				else{
					mat[x+ii][i]=1;
					key-=bin;
				}
				bin/=2;
			}
		}
	}
	//input parser

	static void doAsciiArt(String str){

		int lgh = str.length();
		mat =new int [5*(lgh+1)][5];
		int Char=0;
		for (int i=0;i<lgh;i++){
			Char=(int)str.charAt(i)>=65 && (int)str.charAt(i)<=90 ? listOfChar[(int)str.charAt(i)-64]:
				(int)str.charAt(i)>=97 && (int)str.charAt(i)<=122 ? listOfChar[(int)str.charAt(i)-96]:
					-1;
				setMat(i,Char);
		}
		show(lgh);
	}		

	//

	static void show (int n){
		for (int i=0;i<5;i++){
			for (int ii=0;ii<5*n;ii++){
				if (mat[ii][i]==1)
					System.out.print("X");
				else
					System.out.print(" ");
			}
			System.out.print("\n");
		}
	}

	//main	
	public static void main (String [] a){
		for (String s: a) {
			doAsciiArt(s);	
		}
		
	//	doAsciiArt("your life your choice ");	
	}


}
