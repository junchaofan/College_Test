package sqlTools;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import database.DatabaseTools;
import model.Book;

public class BookTools {
	private static Book newbook;
	public Book getNewbook() {
		return newbook;
	}
	public void setNewbook(Book newbook) {
		BookTools.newbook = newbook;
		String sql="select TSBH,TSMC,TSZZ,TSDJ,IFJC from T_TSXX where TSBH='" + newbook.getIdBook() + "'";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery();
			while(rs.next()){
				newbook.setIdBook(rs.getString("TSBH"));
				newbook.setNameBook(rs.getString("TSMC"));
				newbook.setAuthor(rs.getString("TSZZ"));
				newbook.setPrice(rs.getBigDecimal("TSDJ"));
				newbook.setType(rs.getBoolean("IFJC"));
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	public int return_TSBH() {
		int rt=0;
		String sql="select MAX(TSBH) from T_TSXX";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				rt=rs.getInt("MAX(TSBH)");
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return rt;
	}
	
	public boolean return_SFJC(String idBook) {
		boolean rt=false;
		String sql="select SFJC from T_TSXX where TSBH = ?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, idBook);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				rt=rs.getBoolean("SFJC");
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return rt;
	}

	public List<Book> BookData() {
		String sql="select TSBH,TSMC,TSZZ,TSDJ,SFJC from T_TSXX";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		List<Book> ls=new ArrayList<Book>();
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery(sql);
			while(rs.next()){
				Book book=new Book();
				book.setIdBook(rs.getString("TSBH"));
				book.setNameBook(rs.getString("TSMC"));
				book.setPrice(rs.getBigDecimal("TSDJ"));
				book.setType(rs.getBoolean("SFJC"));
				book.setAuthor(rs.getString("TSZZ"));
				ls.add(book);
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return ls;
	}
	
	public List<Book> BookData(String TSMC) {
		String sql="select TSBH,TSMC,TSZZ,TSDJ,SFJC from T_TSXX where TSMC like'%" + TSMC + "%'";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		List<Book> ls=new ArrayList<Book>();
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery(sql);
			while(rs.next()){
				Book book=new Book();
				book.setIdBook(rs.getString("TSBH"));
				book.setNameBook(rs.getString("TSMC"));
				book.setPrice(rs.getBigDecimal("TSDJ"));
				book.setType(rs.getBoolean("SFJC"));
				book.setAuthor(rs.getString("TSZZ"));
				ls.add(book);
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return ls;
	}
	
	public Book Search_Book(String TSBH) {
		String sql="select * from T_TSXX where TSBH='" + TSBH + "'";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		Book book = null;
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery(sql);
			while(rs.next()){
				book=new Book();
				book.setIdBook(rs.getString("TSBH"));
				book.setNameBook(rs.getString("TSMC"));
				book.setPrice(rs.getBigDecimal("TSDJ"));
				book.setType(rs.getBoolean("SFJC"));
				book.setAuthor(rs.getString("TSZZ"));
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return book;
	}
	
	public int AddBook(Book book) {
		int i=0;
		String sql="insert into T_TSXX (TSBH,TSMC,TSZZ,TSDJ,SFZJ) values(?,?,?,?,?)";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);		
			st.setString(1, book.getIdBook());
			st.setString(2, book.getNameBook());
			st.setString(3, book.getAuthor());
			st.setBigDecimal(4, book.getPrice());
			st.setBoolean(5, book.getType());
			i=st.executeUpdate();
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return i;
	}
	
	public int UpdateBook(Book book) {
		int i=0;
		String sql="update T_TSXX set TSMC=?,TSZZ=?,TSDJ=?,SFJC=? where TSBH= ?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, book.getNameBook());
			st.setString(2, book.getAuthor());
			st.setBigDecimal(3, book.getPrice());
			st.setBoolean(4, book.getType());
			st.setString(5, book.getIdBook());
			i=st.executeUpdate();
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return i;
	}

	//删除图书，同时更新图书编号
	public int DeleteBook(String idbook) {
		int i=0;
		String sql1="delete from T_TSXX where TSBH = ?";
		String sql2="update T_TSXX set TSBH=TSBH-1 where TSBH > ?";
		String sql3="update T_JYXX set TSBH=TSBH-1 where TSBH > ?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql1);
			st.setString(1, idbook);
			i=st.executeUpdate();
			st = conn.prepareStatement(sql2);
			st.setString(1, idbook);
			i=st.executeUpdate();
			st = conn.prepareStatement(sql3);
			st.setString(1, idbook);
			i=st.executeUpdate();
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return i;
	}
	
	public boolean whetherInStock(String TSBH) {
		boolean judge=false;
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		String sql = "select SFJC from T_TSXX where TSBH = ?";
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			st.setString(1, TSBH);
			ResultSet rs = st.executeQuery();
			while (rs.next()) {
				if(rs.getBoolean("SFJC")){
					judge = true;
				}
			}
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return judge;
	}
}

