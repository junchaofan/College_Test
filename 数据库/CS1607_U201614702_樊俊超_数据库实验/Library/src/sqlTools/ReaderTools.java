package sqlTools;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import database.DatabaseTools;
import model.Reader;

public class ReaderTools {
	private static Reader newreader;
	
	public boolean IFFK(String idreader) {
		boolean rt=false;
		String sql="select T_HSXX.JYDH,TSZT,IFFK from T_HSXX,T_JYXX where T_HSXX.JYDH=T_JYXX.JYDH and IFSH=false and DZZH = ?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, idreader);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				rt=rs.getBoolean("IFFK");
				if(rt==true)
					break;
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return rt;
	}
	
	public String return_DZMC(String idreader) {
		String rt = null;
		String sql="select DZMC from T_DZXX where DZZH=?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, idreader);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				rt=rs.getString("DZMC");
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return rt;
	}
	
	public String return_DZDH(String idreader) {
		String rt = null;
		String sql="select DZDH from T_DZXX where DZZH=?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, idreader);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				rt=rs.getString("DZDH");
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return rt;
	}
	
	public boolean IF_borrow(String idreader) {
		boolean rt = false;
		String sql="select * from T_JYXX where DZZH=?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, idreader);
			ResultSet rs = st.executeQuery();
			while(rs.next()) {
				rt=true;
			}
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return rt;
	}
	
	public List<Reader> ReaderData(String idReader) {
		String sql="select DZZH,DZMC,DZDH,DZMM from T_DZXX where DZZH='" + idReader + "'";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		List<Reader> ls=new ArrayList<Reader>();
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery(sql);
			while(rs.next()){
				Reader reader=new Reader();
				reader.setIdReader(rs.getString("DZZH"));
				reader.setNameReader(rs.getString("DZMC"));
				reader.setType(rs.getString("DZDH"));
				reader.setPassword(rs.getString("DZMM"));
				ls.add(reader);
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return ls;
	}
	
	public List<Reader> ReaderData() {
		String sql="select DZZH,DZMC,DZDH,DZMM from T_DZXX";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		List<Reader> ls=new ArrayList<Reader>();
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery();
			while(rs.next()){
				Reader reader=new Reader();
				reader.setIdReader(rs.getString("DZZH"));
				reader.setNameReader(rs.getString("DZMC"));
				reader.setType(rs.getString("DZDH"));
				reader.setPassword(rs.getString("DZMM"));
				ls.add(reader);
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return ls;
	}
	
	public boolean ReaderLogin(String idReader, String password) {
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			String sql = "select DZZH,DZMM from T_DZXX where DZZH='" + idReader + "' and DZMM='" + password+"'";
			PreparedStatement st =conn.prepareStatement(sql);
			ResultSet rs = st.executeQuery(sql);
			if (rs.next()) {
				return true;
			}
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}
	
	public int AddReader(Reader reader) {
		int i=0;
		String sql="insert into T_DZXX (DZZH,DZMC,DZDH,DZMM) values(?,?,?,?)";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);		
			st.setString(1, reader.getIdReader());
			st.setString(2, reader.getNameReader());
			st.setString(3, reader.getType());
			st.setString(4, reader.getPassword());
			i=st.executeUpdate();
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return i;
	}
	
	public int UpdateReader(Reader reader) {
		int i=0;
		String sql="update T_DZXX set DZMC=?,DZDH=?,DZMM=? where DZZH=?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, reader.getNameReader());
			st.setString(2, reader.getType());
			st.setString(3, reader.getPassword());
			st.setString(4, reader.getIdReader());
			i=st.executeUpdate();
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return i;
	}
	
	public int DeleteReader(String idreader) {
		int i=0;
		String sql="delete from T_DZXX where DZZH=?";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		try {
			PreparedStatement st = conn.prepareStatement(sql);
			st.setString(1, idreader);
			i=st.executeUpdate();
			st.close();
			conn.close();
		}catch (SQLException e) {
		e.printStackTrace();
		}
		return i;
	}
	public Reader getNewreader() {
		return newreader;
	}
	public void setNewreader(Reader newreader) {
		ReaderTools.newreader = newreader;
		String sql="select DZZH,DZMC,DZDH,DZMM from T_DZXX where DZZH='" + newreader.getIdReader() + "'";
		DatabaseTools db = new DatabaseTools();
		Connection conn = db.getConn();
		ResultSet rs=null;
		try {
			PreparedStatement st =conn.prepareStatement(sql);
			rs=st.executeQuery();
			while(rs.next()){
				newreader.setIdReader(rs.getString("DZZH"));
				newreader.setNameReader(rs.getString("DZMC"));
				newreader.setType(rs.getString("DZDH"));
				newreader.setPassword(rs.getString("DZMM"));
			}
			rs.close();
			st.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	
}
