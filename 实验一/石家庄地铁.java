//信1603 20163574  高广润
package test5;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

abstract class Subway{
	private int[]num;
	private String[]station;
	private String[]message;
	abstract void show();
	abstract int Chaxun();
	abstract int buy();
}

class FirstLineSubway extends Subway
{
	private String First[]={"洨河大道","南村","石家庄东站","火炬广场","留村","白佛","朝晖桥","谈固","北宋","体育场","博物院","北国商城","平安大街","解放广场","新百广场","烈士陵园","和平医院","长城桥","时光街","西王"};
	public void show()
	{
		System.out.println("1号线：");
		for(int i=0;i<20;i++)
		{
			System.out.println("站点"+(i+1)+" "+First[i]);
		}
	}
	public int Chaxun(){
		return 0;
	}
	public int buy(){
		return 0;
	}
	
}
class ThirdLineSubway extends Subway
{
	 private String Third[]={"市二中","新百广场","东里","槐安桥","西三教","石家庄站"};
	public void show(){
		
		System.out.println("3号线：");
		for(int i=0;i<6;i++)
		{
			System.out.println("站点"+(i+1)+" "+Third[i]);
		}
		
	}
	public int Chaxun(){
		return 0;
	}
	public int buy(){
		return 0;
	}
}

class Subway1
{
	public String[]Subway1;
	public String[]Subway2;

	public Subway1() 
	{
		Subway1 = new String[20];
		Subway1[0] = "洨河大道";
		Subway1[1] = "南村";
		Subway1[2] = "石家庄东站";
		Subway1[3] = "火炬广场";
		Subway1[4] = "留村";
		Subway1[5] = "白佛";
		Subway1[6] = "朝晖桥";
		Subway1[7] = "谈固";
		Subway1[8] = "北宋";
		Subway1[9] = "体育场";
		Subway1[10] = "博物馆";
		Subway1[11] = "北国商城";
		Subway1[12] = "平安大街";
		Subway1[13] = "解放广场";
		Subway1[14] = "新百广场";          ///
		Subway1[15] = "烈士陵园";
		Subway1[16] = "和平医院";
		Subway1[17] = "长城桥";
		Subway1[18] = "时光街";
		Subway1[19] = "西王";
		Subway2 = new String[6];
		Subway2[0] = "市二中";
		Subway2[1] = "新百广场";          ///
		Subway2[2] = "东里";
		Subway2[3] = "槐安街";
		Subway2[4] = "西三教";
		Subway2[5] = "石家庄站";
	}


	public int search(String n1,String n2)
	{
		int flag1=-1,flag2=-1;
	    int k1=0,k2=0; 
	    int count = 0;
	    for(int i = 0;i<19;i++) 
	    {
	    	if(Subway1[i].equals(n1)) 
	    	{
	    		flag1=1;
	    		k1 = i;
	    	}
	    	if(Subway1[i].equals(n2)) 
	    	{
	    		flag2 = 1;
	    		k2 = i;
	    	}
	    }
	    for(int i = 0;i<6;i++) 
	    {
	    	if(Subway2[i].equals(n1)) 
	    	{
	    		flag1=0;
	    		k1 = i;
	    	}
	    	if(Subway2[i].equals(n2)) 
	    	{
	    		flag2 = 0;
	    		k2 = i;
	    	}
	    }
	    
	    if(flag1 == 1&&flag2 == 1) 
	    {
	    	count = Math.abs(k1-k2);
	    	System.out.println(count+"站");
	    	if(k1>k2) 
	    	{
	    		for(int i = k1;i>=k2;i--)
	    			System.out.println(Subway1[i]+" 1号线");
	    	}
	    	if(k1<k2) 
	    	{
	    		for(int i = k1;i<=k2;i++)
	    			System.out.println(Subway1[i]+" 1号线");
	    	}
	    }
	    if(flag1==1&&flag2==0) 
	    {
	    	count = Math.abs(k1-14)+Math.abs(k2-1);
	    	System.out.println(count+"站");
	    	if(k1>14) 
	    	{
	    		for(int i = k1;i>=14;i--)
	    			System.out.println(Subway1[i]+" 1号线");
	    	}
	    	if(k1<14) 
	    	{
	    		for(int i = k1;i<=14;i++)
	    			System.out.println(Subway1[i]+" 1号线");
	    	}
	    	if(k2>1) 
	    	{
	    		for(int i = 2;i<=k2;i++)
	    			System.out.println(Subway2[i]+" 3号线");
	    	}
	    	if(k2<1) 
	    	{
	    		for(int i = 1;i<=k2;i--)
	    			System.out.println(Subway2[i]+" 3号线");
	    	}
	    }
	    if(flag1==0&&flag2==0) 
	    {
	    	count = Math.abs(k1-k2+1);
	    	System.out.println(count+"站");
	    	if(k1>k2) 
	    	{
	    		for(int i = k1;i>=k2;i--)
	    			System.out.println(Subway2[i]+" 3号线");
	    	}
	    	if(k1<k2) 
	    	{
	    		for(int i = k1;i<=k2;i++)
	    			System.out.println(Subway2[i]+" 3号线");
	    	}
	    }
	    if(flag1==0&&flag2==1)
	    {
	    	count = Math.abs(k1-1)+Math.abs(k2-14);
	    	System.out.println(count+"站");
	    	if(k1>1) 
	    	{
	    		for(int i = 2;i<=k1;)
	    			System.out.println(Subway2[i]+" 3号线");
	    	}
	    	 if(k1<1) 
	    	{
	    		for(int i = 0;i<=k1;i++)
	    			System.out.println(Subway2[i]+" 3号线");
	    	}
	    	if(k2>14) 
	    	{
	    		for(int i = k2;i>=14;i--)
	    			System.out.println(Subway1[i]+" 1号线");
	    	}
	    	 if(k2<14) 
	    	{
	    		for(int i = 14;i>=k2;i--)
	    			System.out.println(Subway1[i]+" 1号线");
	    	}
	    }
	    return count;
}
public void buyTicket() throws IOException
{
	Scanner inn=new Scanner (System.in);
	String Qzhan = null;
	String Zzhan = null;
	int num = 0;
	System.out.println("                    欢迎乘坐石家庄地铁                                                          ");
	System.out.println("***************************************************************");
	
	
	System.out.print("起始站:");
	Qzhan=inn.nextLine();
	
	System.out.print("终点站:");
	Zzhan=inn.nextLine();

	System.out.print("购票数量:");
	num = inn.nextInt();
	
	int c = search(Qzhan, Zzhan);
	
    int sum = 0;
    if(c%3==0)sum = c/3;
    else sum = c/3+1;
    
    System.out.println("单票价:"+sum);
    System.out.println("总价:"+(int)(sum*num));
    System.out.println("*************************************************");
    
	FileWriter Fw = null;
    try {
        //创建字符输出流
    	Fw = new FileWriter("shijiazhuang-subway.txt",true);
    	Fw.write("1号线：洨河大道、\n南村、\n石家庄东站、\n火炬广场、\n留村、\n白佛、\n朝晖桥、\n谈固、\n北宋、\n体育场、\n博物院、\n北国商城、\n平安大街、\n解放广场、\n新百广场、\n烈士陵园、\n和平医院、\n长城桥、\n时光街、\n西王。\r\n");
    	Fw.write("3号线：    市二中、\n新百广场、\n东里、\n槐安桥、\n西三教、\n石家庄站。\r\n");
    	Fw.write("起始站:"+Qzhan+"  "+"终点站:"+Zzhan+"  "+"总价:"+(int)(sum*num)+"\r\n");
    } catch (IOException ioe) {
        ioe.printStackTrace();
    } finally {
        //使用finally块来关闭文件输出流	
        if (Fw != null) {
        	Fw.close();
        }
    }
    
    
    
}



}
public class SubwayManager 
{
	public static void main(String[] args) throws IOException 
	{
		Scanner in=new Scanner (System.in);
		System.out.println("***************************************************************");
		System.out.println("                     欢迎乘坐石家庄地铁                                                     ");
		System.out.println("***************************************************************");
		System.out.println("              1,	显示具体线路信息；                                                   ");
		System.out.println("              2,		购票；                                                   ");
		System.out.println("***************************************************************");
		int i;
		Subway First=new FirstLineSubway();
		
		Subway Third=new ThirdLineSubway();
		while(true)
		{
			System.out.print("请输入:");
		
			i=in.nextInt();
		switch(i)
		{
		case 1:
			int j;
			System.out.println("***************************************************************");
			System.out.println("                      石家庄地铁线路图                                                      ");
			System.out.println("***************************************************************");
			System.out.println("0.全部线路");
			System.out.println("1.1号线线路");
			System.out.println("2.3号线线路");
			System.out.print("请输入:");
			j=in.nextInt();
			
			System.out.println("***************************************************************");
			System.out.println("石家庄地铁线路图");
			System.out.println("***************************************************************");
			if(j==1)
			{
				First.show();
				System.out.println("***************************************************************");
			}
			else if(j==2)
			{
				Third.show();
				System.out.println("***************************************************************");
			}
			else if(j==0)
			{
				First.show();
				Third.show();
				System.out.println("***************************************************************");
			}
			break;
		case 2:
			System.out.println("***************************************************************");
			Subway1 sm =  new Subway1();
			sm.buyTicket();
			break;

		}
		}
	}

}