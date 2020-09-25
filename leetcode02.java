package leetcode.cn;
/**
 * 寻找两个正序数组中的中位数；
 */
import java.util.Arrays;

public class leetcode02 {
	public static void main(String[] args) {
		int a[]= {1,25,41,25,3,21,5,4};
		int b[]= {4,54,2,36,78,95,45,4};
		Arrays.sort(a);
		Arrays.sort(b);
		int c[]=all(a,b);
		System.out.print("a数组为：");
		System.out.println(Arrays.toString(a));
		System.out.print("b数组为：");
		System.out.println(Arrays.toString(b));
		System.out.print("a，b数组合并为c数组：");
		System.out.println(Arrays.toString(c));
		double mid=0;
		
	if(c.length%2==0) {
		mid=(c[(c.length)/2]+c[(c.length)/2-1])/2;
	}else if(c.length%2!=0) {
		mid=c[(c.length-1)/2];
	}
	System.out.print("数组c的中位数为：");
	System.out.print(mid);
	
	}
	static int[] all(int[] a,int[] b) {
		int length=a.length+b.length;
		int c[]=new int[length];
		int j=0,k=0,h=0;
		while(j<a.length && k<b.length) {
			if(a[j]<b[k]) {
				c[h]=a[j];
				j++;
				h++;
			}else if(a[j]>b[k]) {
				c[h]=b[k];
				h++;
				k++;
			}else {
				c[h]=a[j];
				h++;
				j++;
				c[h]=b[k];
				k++;
				h++;
			}
		}
		while(j<a.length) {
			c[h]=a[j];
			h++;
			j++;
		}
		while(k<b.length) {
			c[h]=b[k];
			h++;
			k++;
		}
		return c;
	}

}
