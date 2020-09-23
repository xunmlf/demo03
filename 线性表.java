package classtwo.cn;

import java.util.Arrays;

public class 线性表 {
	public static void main(String[] args) {
		int a[]= {50,7,66,9,1,10,45,100,12};
		int b[]= {3,1,5,4,6,89,47};
		Arrays.sort(a);     //数组排好序
		Arrays.sort(b); 
		System.out.println(Arrays.toString(a));
		System.out.println(Arrays.toString(b));
		int c[]=zuhe(a,b);
		System.out.println(Arrays.toString(c));
	}
	static int[] zuhe (int[] a,int[] b) {
		int length=a.length+b.length;
	    int c[]=new int[length];
	    int l=0,j=0,k=0;
	    while(j<a.length && k<b.length) {
	    	if(a[j]<b[k]) {
	    		c[l++]=a[j++];
	    	}else if(a[j]>b[k]) {
	    		c[l++]=b[k++];
	    	}else {
	    		c[l++]=b[k++];
	    		c[l++]=a[j++];
	    	}
	    }
	    while(j<a.length) {
	    	c[l++]=a[j++];
	    }
	    while(k<b.length) {
	    	c[l++]=b[k++];
	    }		return c;
	}
}
