package model;

public class Reader {
	private String idReader;
	private String nameReader;
	private String phone;
	private String password;
	public String getIdReader() {
		return idReader;
	}
	public void setIdReader(String idReader) {
		this.idReader = idReader;
	}
	public String getNameReader() {
		return nameReader;
	}
	public void setNameReader(String nameReader) {
		this.nameReader = nameReader;
	}
	public String getType() {
		return phone;
	}
	public void setType(String phone) {
		this.phone = phone;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}


	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((idReader == null) ? 0 : idReader.hashCode());
		result = prime * result + ((nameReader == null) ? 0 : nameReader.hashCode());
		result = prime * result + ((phone == null) ? 0 : phone.hashCode());
		return result;
	}

	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Reader other = (Reader) obj;
		if (idReader == null) {
			if (other.idReader != null)
				return false;
		} else if (!idReader.equals(other.idReader))
			return false;
		if (nameReader == null) {
			if (other.nameReader != null)
				return false;
		} else if (!nameReader.equals(other.nameReader))
			return false;
		if (phone == null) {
			if (other.phone != null)
				return false;
		} else if (!phone.equals(other.phone))
			return false;
		return true;
	}

	public String toString() {
		return "Reader [idReader=" + idReader + ", nameReader=" + nameReader + ", phone=" + phone 
				+ ", password=" + password + "]";
	}

}
