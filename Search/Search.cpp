
#include "Search.h"

EmployNumCondition::EmployNumCondition(string search_pattern) {
	this->employee_number = stoi(search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.employee_number % 100000000 == this->employee_number;
	};
}

NameCondition::NameCondition(string search_pattern) {
	this->name = search_pattern;

	Match = [this](Employee& in) -> bool {
		return in.first_name + " " + in.last_name == this->name;
	};
}

FirstNameCondition::FirstNameCondition(string search_pattern) {
	this->first_name = search_pattern;

	Match = [this](Employee& in) -> bool {
		return in.first_name == this->first_name;
	};
}

LastNameCondition::LastNameCondition(string search_pattern) {
	this->last_name = search_pattern;

	Match = [this](Employee& in) -> bool {
		return in.last_name == this->last_name;
	};
}

PhoneNumCondition::PhoneNumCondition(string search_pattern) {
	this->phone_num = search_pattern;

	Match = [this](Employee& in) -> bool {
		return "010-" + std::to_string(in.phone_num_mid) + "-" + std::to_string(in.phone_num_last) == this->phone_num;
	};
}

PhoneNumMidCondition::PhoneNumMidCondition(string search_pattern) {
	this->phone_num_mid = stoi(search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.phone_num_mid == this->phone_num_mid;
	};
}

PhoneNumLastCondition::PhoneNumLastCondition(string search_pattern) {
	this->phone_num_last = stoi(search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.phone_num_last == this->phone_num_last;
	};
}

BirthCondition::BirthCondition(string search_pattern) {
	this->birth = stoi(search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.birth == this->birth;
	};
}

BirthYearCondition::BirthYearCondition(string search_pattern) {
	this->year = stoi(search_pattern);

	Match = [this](Employee& in) -> bool {
		unsigned year = in.birth / 10000;
		return year == this->year;
	};
}

BirthMonthCondition::BirthMonthCondition(string search_pattern) {
	this->month = stoi(search_pattern);
	if (this->month < 0 || this->month > 12) {
		throw std::out_of_range("Search month range error!");
	}

	Match = [this](Employee& in) -> bool {
		unsigned month = in.birth % 10000 / 100;
		if (month < 0 || month > 12) {
			throw std::out_of_range("Month range error!");
		}
		return month == this->month;
	};
}

BirthDayCondition::BirthDayCondition(string search_pattern) {
	this->day = stoi(search_pattern);
	if (this->day < 0 || this->day > 31) {
		throw std::out_of_range("Search day range error!");
	}

	Match = [this](Employee & in) -> bool {
		unsigned day = in.birth % 100;
		if (day < 0 || day > 31) {
			throw std::out_of_range("Day range error!");
		}
		return day == this->day;
	};
}

ClCondition::ClCondition(string search_pattern) {
	this->cl = StrToCL(search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.cl == this->cl;
	};
}

CertiCondition::CertiCondition(string search_pattern) {
	this->certi = StrToCerti(search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.certi == this->certi;
	};
}

void Search::SetEmployeeList(Employees* employees_ptr) {
	this->employees_ = employees_ptr;
}

employeeList Search::DoSearch(SearchType  search_type, string search_pattern) {
	employeeList searchOutput;

	switch (search_type)	{
	case SearchType::EMPLOYEE_NUM: 	 this->search_condition = new EmployNumCondition(search_pattern);	  break;
	case SearchType::NAME:       	 this->search_condition = new NameCondition(search_pattern);	      break;
	case SearchType::FIRST_NAME:	 this->search_condition = new FirstNameCondition(search_pattern);	  break;
	case SearchType::LAST_NAME:		 this->search_condition = new LastNameCondition(search_pattern);	  break;
	case SearchType::PHONE_NUM:  	 this->search_condition = new PhoneNumCondition(search_pattern);	  break;
	case SearchType::PHONE_NUM_MID:	 this->search_condition = new PhoneNumMidCondition(search_pattern);	  break;
	case SearchType::PHONE_NUM_LAST: this->search_condition = new PhoneNumLastCondition(search_pattern);  break;
	case SearchType::BIRTHDAY:	     this->search_condition = new BirthCondition(search_pattern);	      break;
	case SearchType::BIRTHDAY_YEAR:	 this->search_condition = new BirthYearCondition(search_pattern);	  break;
	case SearchType::BIRTHDAY_MONTH: this->search_condition = new BirthMonthCondition(search_pattern);	  break;
	case SearchType::BIRTHDAY_DAY:	 this->search_condition = new BirthDayCondition(search_pattern);	  break;
	case SearchType::CL:	         this->search_condition = new ClCondition(search_pattern);	          break;
	case SearchType::CERTI:	         this->search_condition = new CertiCondition(search_pattern);	      break;
	default: throw std::out_of_range("SearchType range error!");
	}

	searchOutput = this->employees_->Search(this->search_condition->Match);

	delete this->search_condition;

	return searchOutput;
}
