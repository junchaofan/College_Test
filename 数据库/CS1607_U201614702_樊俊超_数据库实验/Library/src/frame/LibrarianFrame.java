package frame;

import javax.swing.JFrame;

public class LibrarianFrame extends JFrame implements Runnable {

	/**
	 * Java�����л�������ͨ��������ʱ�ж����serialVersionUID����֤�汾һ���Ե�
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