package frame;

import javax.swing.JFrame;

public class ReaderFrame extends JFrame implements Runnable {

	/**
	 * Java�����л�������ͨ��������ʱ�ж����serialVersionUID����֤�汾һ���Ե�
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