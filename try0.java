import javax.swing.*;

public class try0 extends JFrame {
	public try0() {
		this.setTitle("登录页面");
		this.setBounds(100, 100, 600, 500);
		this.setLayout(null);
		JLabel name=new JLabel("用户名");
		JTextField txtname=new JTextField(10);
		JLabel pwd=new JLabel("密码");
		JTextField txtpwd=new JTextField(10);
		JButton btn=new JButton("登录");
		name.setBounds(100,100,80,50);
		pwd.setBounds(100,200,80,50);
		txtname.setBounds(350,100,200,50);
		txtpwd.setBounds(350,200,200,50);
		btn.setBounds(200,300,200,50);
		add(name);
		add(txtname);
		add(pwd);
		add(txtpwd);
		add(btn);
	}
	public static void main(String[] args) {
		try0 t=new try0();
		t.setVisible(true);
	}
}
