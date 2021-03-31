package frame;

import javax.swing.JFrame;

public class LibrarianFrame extends JFrame implements Runnable {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;

	public LibrarianFrame() {
	}


	public void run() {
		setUndecorated(true);
		setResizable(false);
		setSize(520, 402);
		Book_AllReader all_ReaderFrame = new Book_AllReader();
		all_ReaderFrame.setVisible(true);

	}

}