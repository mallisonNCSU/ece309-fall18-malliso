#include <stdio.h>

class IntInf {
	private:
	int type; //-1 means neginf, 0 means integer, 1 means posinf
	int number; //this is relevant if type is 0
	public:
	IntInf(int t=0, int numb=0):number(numb) {type = t;}
	
	IntInf& operator=(const IntInf& rhs) {
		type = rhs.type;
		number = rhs.number;
		return *this;
	}
	IntInf& operator=(int x) {
		type = 0;
		number = x;
		return *this;
	}
	IntInf operator+(const IntInf& rhs) {
		switch(rhs.type) {
			case -1:
				if(type==1) {
					return IntInf(1);
				} else {
					return IntInf(-1);
				}
				break;
			case 0:
				if(type==0) {
					return IntInf(0, number+rhs.number);
				} else {
					return IntInf(type);
				}
				break;
			case 1:
				if(type==-1) {
					return IntInf(-1);
				} else {
					return IntInf(1);
				}
				break;
		}
		return this;
	}
	IntInf operator+(int x) {
		if(type==0) {
			return IntInf(0, number+x);
		} else {
			return IntInf(type, number);
		}
	}
	IntInf operator-(const IntInf& rhs) {
		switch(rhs.type) {
			case -1:
				if(type==-1) {
					return IntInf(-1);
				} else {
					return IntInf(1);
				}
				break;
			case 0:
				if(type==0) {
					return IntInf(0, number-rhs.number);
				} else {
					return IntInf(type*-1);
				}
				break;
			case 1:
				if(type==1) {
					return IntInf(1);
				} else {
					return IntInf(-1);
				}
				break;
		}
		return this;
	}
	IntInf operator-(int x) {
		if(type==0) {
			return IntInf(0, number-x);
		} else {
			return IntInf(type, number);
		}
	}
	IntInf operator*(const IntInf& rhs) {
		if((type!=0) && (rhs.type!=0)) {
			return IntInf(type*rhs.type);
		}
		if((type==0) && (rhs.type==0)) {
			return IntInf(0, number*rhs.number);
		} else {
			if(type==0) {
				if(type*rhs.number > 0) {
					return IntInf(1);
				} else if(type*rhs.number < 0) {
					return IntInf(-1);
				} else {
					return IntInf(0,0);
				}
			}
			if(rhs.type==0) {
				if(rhs.type*number > 0) {
					return IntInf(1);
				} else if(rhs.type*number < 0) {
					return IntInf(-1);
				} else {
					return IntInf(0,0);
				}
			}
		}
		return this;
	}
	IntInf operator*(int x) {
		if(type==0) {
			return IntInf(0, number*x);
		} else {
				if(type*x > 0) {
					return IntInf(1);
				} else if(type*x < 0) {
					return IntInf(-1);
				} else {
					return IntInf(0,0);
				}
		}
	}
	IntInf operator/(const IntInf& rhs) {
		if((type!=0) && (rhs.type!=0)) {
			return IntInf(type*rhs.type);
		}
		if((type==0) && (rhs.type==0)) {
			return IntInf(0, number/rhs.number);
		} else {
			if(rhs.type==0) {
				if(type*rhs.number > 0) {
					return IntInf(1);
				} else if(type*rhs.number < 0) {
					return IntInf(-1);
				} else {
					return IntInf(type);
				}
			}
			if(type==0) {
				return IntInf(0,0);
			}
		}
		return this;		
	}	
	IntInf operator/(int x) {
		if(type==0) {
			return IntInf(0, number/x);
		} else {
			if(type*x > 0) {
				return IntInf(1);
			} else if(type*x < 0) {
				return IntInf(-1);
			} else {
				return IntInf(type);
			}
		}
	}
	bool operator==(const IntInf& rhs) {
		if((type==0) && (rhs.type==0)) {
			return number == rhs.number;
		} else {
			return false;
		}
	}
	bool operator==(int x) {
		if(type==0) {
			return number == x;
		} else {
			return false;
		}
	}
	bool operator>(const IntInf& rhs) {
		if((type==0) && (rhs.type==0)) {
			return number > rhs.number;
		} else {
			return type > rhs.type;
		}
	}
	bool operator>(int x) {
		if(type==0) {
			return number > x;
		} else {
			return type > 0;
		}	
	}
	bool operator<(const IntInf& rhs) {
		if((type==0) && (rhs.type==0)) {
			return number < rhs.number;
		} else {
			return type < rhs.type;
		}	
	}
	bool operator<(int x) {
		if(type==0) {
			return number < x;
		} else {
			return type < 0;
		}	
	}
	int getType() {
		return type;
	}
	int getNumber() {
		return number;
	}
};