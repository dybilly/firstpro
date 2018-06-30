//��1603 20163574  �߹���
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
	private String First[]={"���Ӵ��","�ϴ�","ʯ��ׯ��վ","���㳡","����","�׷�","������","̸��","����","������","����Ժ","�����̳�","ƽ�����","��Ź㳡","�°ٹ㳡","��ʿ��԰","��ƽҽԺ","������","ʱ���","����"};
	public void show()
	{
		System.out.println("1���ߣ�");
		for(int i=0;i<20;i++)
		{
			System.out.println("վ��"+(i+1)+" "+First[i]);
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
	 private String Third[]={"�ж���","�°ٹ㳡","����","������","������","ʯ��ׯվ"};
	public void show(){
		
		System.out.println("3���ߣ�");
		for(int i=0;i<6;i++)
		{
			System.out.println("վ��"+(i+1)+" "+Third[i]);
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
		Subway1[0] = "���Ӵ��";
		Subway1[1] = "�ϴ�";
		Subway1[2] = "ʯ��ׯ��վ";
		Subway1[3] = "���㳡";
		Subway1[4] = "����";
		Subway1[5] = "�׷�";
		Subway1[6] = "������";
		Subway1[7] = "̸��";
		Subway1[8] = "����";
		Subway1[9] = "������";
		Subway1[10] = "�����";
		Subway1[11] = "�����̳�";
		Subway1[12] = "ƽ�����";
		Subway1[13] = "��Ź㳡";
		Subway1[14] = "�°ٹ㳡";          ///
		Subway1[15] = "��ʿ��԰";
		Subway1[16] = "��ƽҽԺ";
		Subway1[17] = "������";
		Subway1[18] = "ʱ���";
		Subway1[19] = "����";
		Subway2 = new String[6];
		Subway2[0] = "�ж���";
		Subway2[1] = "�°ٹ㳡";          ///
		Subway2[2] = "����";
		Subway2[3] = "������";
		Subway2[4] = "������";
		Subway2[5] = "ʯ��ׯվ";
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
	    	System.out.println(count+"վ");
	    	if(k1>k2) 
	    	{
	    		for(int i = k1;i>=k2;i--)
	    			System.out.println(Subway1[i]+" 1����");
	    	}
	    	if(k1<k2) 
	    	{
	    		for(int i = k1;i<=k2;i++)
	    			System.out.println(Subway1[i]+" 1����");
	    	}
	    }
	    if(flag1==1&&flag2==0) 
	    {
	    	count = Math.abs(k1-14)+Math.abs(k2-1);
	    	System.out.println(count+"վ");
	    	if(k1>14) 
	    	{
	    		for(int i = k1;i>=14;i--)
	    			System.out.println(Subway1[i]+" 1����");
	    	}
	    	if(k1<14) 
	    	{
	    		for(int i = k1;i<=14;i++)
	    			System.out.println(Subway1[i]+" 1����");
	    	}
	    	if(k2>1) 
	    	{
	    		for(int i = 2;i<=k2;i++)
	    			System.out.println(Subway2[i]+" 3����");
	    	}
	    	if(k2<1) 
	    	{
	    		for(int i = 1;i<=k2;i--)
	    			System.out.println(Subway2[i]+" 3����");
	    	}
	    }
	    if(flag1==0&&flag2==0) 
	    {
	    	count = Math.abs(k1-k2+1);
	    	System.out.println(count+"վ");
	    	if(k1>k2) 
	    	{
	    		for(int i = k1;i>=k2;i--)
	    			System.out.println(Subway2[i]+" 3����");
	    	}
	    	if(k1<k2) 
	    	{
	    		for(int i = k1;i<=k2;i++)
	    			System.out.println(Subway2[i]+" 3����");
	    	}
	    }
	    if(flag1==0&&flag2==1)
	    {
	    	count = Math.abs(k1-1)+Math.abs(k2-14);
	    	System.out.println(count+"վ");
	    	if(k1>1) 
	    	{
	    		for(int i = 2;i<=k1;)
	    			System.out.println(Subway2[i]+" 3����");
	    	}
	    	 if(k1<1) 
	    	{
	    		for(int i = 0;i<=k1;i++)
	    			System.out.println(Subway2[i]+" 3����");
	    	}
	    	if(k2>14) 
	    	{
	    		for(int i = k2;i>=14;i--)
	    			System.out.println(Subway1[i]+" 1����");
	    	}
	    	 if(k2<14) 
	    	{
	    		for(int i = 14;i>=k2;i--)
	    			System.out.println(Subway1[i]+" 1����");
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
	System.out.println("                    ��ӭ����ʯ��ׯ����                                                          ");
	System.out.println("***************************************************************");
	
	
	System.out.print("��ʼվ:");
	Qzhan=inn.nextLine();
	
	System.out.print("�յ�վ:");
	Zzhan=inn.nextLine();

	System.out.print("��Ʊ����:");
	num = inn.nextInt();
	
	int c = search(Qzhan, Zzhan);
	
    int sum = 0;
    if(c%3==0)sum = c/3;
    else sum = c/3+1;
    
    System.out.println("��Ʊ��:"+sum);
    System.out.println("�ܼ�:"+(int)(sum*num));
    System.out.println("*************************************************");
    
	FileWriter Fw = null;
    try {
        //�����ַ������
    	Fw = new FileWriter("shijiazhuang-subway.txt",true);
    	Fw.write("1���ߣ����Ӵ����\n�ϴ塢\nʯ��ׯ��վ��\n���㳡��\n���塢\n�׷�\n�����š�\n̸�̡�\n���Ρ�\n��������\n����Ժ��\n�����̳ǡ�\nƽ����֡�\n��Ź㳡��\n�°ٹ㳡��\n��ʿ��԰��\n��ƽҽԺ��\n�����š�\nʱ��֡�\n������\r\n");
    	Fw.write("3���ߣ�    �ж��С�\n�°ٹ㳡��\n���\n�����š�\n�����̡�\nʯ��ׯվ��\r\n");
    	Fw.write("��ʼվ:"+Qzhan+"  "+"�յ�վ:"+Zzhan+"  "+"�ܼ�:"+(int)(sum*num)+"\r\n");
    } catch (IOException ioe) {
        ioe.printStackTrace();
    } finally {
        //ʹ��finally�����ر��ļ������	
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
		System.out.println("                     ��ӭ����ʯ��ׯ����                                                     ");
		System.out.println("***************************************************************");
		System.out.println("              1,	��ʾ������·��Ϣ��                                                   ");
		System.out.println("              2,		��Ʊ��                                                   ");
		System.out.println("***************************************************************");
		int i;
		Subway First=new FirstLineSubway();
		
		Subway Third=new ThirdLineSubway();
		while(true)
		{
			System.out.print("������:");
		
			i=in.nextInt();
		switch(i)
		{
		case 1:
			int j;
			System.out.println("***************************************************************");
			System.out.println("                      ʯ��ׯ������·ͼ                                                      ");
			System.out.println("***************************************************************");
			System.out.println("0.ȫ����·");
			System.out.println("1.1������·");
			System.out.println("2.3������·");
			System.out.print("������:");
			j=in.nextInt();
			
			System.out.println("***************************************************************");
			System.out.println("ʯ��ׯ������·ͼ");
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