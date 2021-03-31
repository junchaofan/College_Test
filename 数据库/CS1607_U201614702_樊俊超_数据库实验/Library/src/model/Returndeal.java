package model;

public class Returndeal {
	private String idReturnBook;
	private String idJYBook;
	private String JYtime;
	private String HStime;
	private boolean TStype;
	private boolean FKtype;
	private boolean SHtype;

	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((idReturnBook == null) ? 0 : idReturnBook.hashCode());
		return result;
	}

	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Returndeal other = (Returndeal) obj;
		if (idReturnBook == null) {
			if (other.idReturnBook != null)
				return false;
		} else if (!idReturnBook.equals(other.idReturnBook))
			return false;
		if (idJYBook == null) {
			if (other.idJYBook != null)
				return false;
		} else if (!idJYBook.equals(other.idJYBook))
			return false;
		if ( JYtime == null) {
			if (other.JYtime != null)
				return false;
		} else if (!JYtime.equals(other.JYtime))
			return false;
		if ( HStime == null) {
			if (other.HStime != null)
				return false;
		} else if (!HStime.equals(other.HStime))
			return false;
		if(TStype==other.TStype && FKtype==other.FKtype && SHtype==other.SHtype)
			return true;
		else
			return false;
	}

	public String toString() {
		return "Returndeal [idReturnBook=" + idReturnBook + ", idJYBook=" + idJYBook   + ", JYtime="+ JYtime 
				+ ", HStime" + HStime + ", TStype=" + TStype + ", FKtype=" + FKtype + ", SHtype=" + SHtype + "]";
	}

	public String getIdReturnBook() {
		return idReturnBook;
	}

	public void setIdReturnBook(String idReturnBook) {
		this.idReturnBook = idReturnBook;
	}

	public String getIdJYBook() {
		return idJYBook;
	}

	public void setIdJYBook(String idJYBook) {
		this.idJYBook = idJYBook;
	}

	public String getHStime() {
		return HStime;
	}

	public void setHStime(String hStime) {
		HStime = hStime;
	}

	public boolean isTStype() {
		return TStype;
	}

	public void setTStype(boolean tStype) {
		TStype = tStype;
	}

	public boolean isFKtype() {
		return FKtype;
	}

	public void setFKtype(boolean fKtype) {
		FKtype = fKtype;
	}

	public boolean isSHtype() {
		return SHtype;
	}

	public void setSHtype(boolean sHtype) {
		SHtype = sHtype;
	}

	public String getJYtime() {
		return JYtime;
	}

	public void setJYtime(String jYtime) {
		JYtime = jYtime;
	}

}
