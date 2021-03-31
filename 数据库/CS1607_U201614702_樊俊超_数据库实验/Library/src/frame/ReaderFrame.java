package frame;

import javax.swing.JFrame;

public class ReaderFrame extends JFrame implements Runnable {

	/**
	 * Java的序列化机制是通过在运行时判断类的serialVersionUID来验证版本一致性的
	 */
	private static final long serialVersionUID = 1L;

	
	public ReaderFrame() {
	}

	public void run() {
		setUndecorated(true);
		setResizable(false);
		setSize(529, 527);
		Book_Serach search_BookFrame = new Book_Serach();
		search_BookFrame.setVisible(true);
	}

}