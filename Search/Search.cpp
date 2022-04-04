
#include "Search.h"

EmployNumCondition::EmployNumCondition(SearchInput in) {
	this->employee_number = stoi(in.search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.employee_number == this->employee_number;
	};
}

NameCondition::NameCondition(SearchInput in) {
	this->name = in.search_pattern;

	Match = [this](Employee& in) -> bool {
		return in.first_name + in.last_name == this->name;
	};
}

FirstNameCondition::FirstNameCondition(SearchInput in) {
	this->first_name = in.search_pattern;

	Match = [this](Employee& in) -> bool {
		return in.first_name == this->first_name;
	};
}

LastNameCondition::LastNameCondition(SearchInput in) {
	this->last_name = in.search_pattern;

	Match = [this](Employee& in) -> bool {
		return in.last_name == this->last_name;
	};
}

PhoneNumCondition::PhoneNumCondition(SearchInput in) {
	this->phone_num = in.search_pattern;

	Match = [this](Employee& in) -> bool {
		return std::to_string(in.phone_num_mid) + std::to_string(in.phone_num_last) == this->phone_num;
	};
}

PhoneNumMidCondition::PhoneNumMidCondition(SearchInput in) {
	this->phone_num_mid = stoi(in.search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.phone_num_mid == this->phone_num_mid;
	};
}

PhoneNumLastCondition::PhoneNumLastCondition(SearchInput in) {
	this->phone_num_last = stoi(in.search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.phone_num_last == this->phone_num_last;
	};
}

BirthCondition::BirthCondition(SearchInput in) {
	this->birth = stoi(in.search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.birth == this->birth;
	};
}

BirthYearCondition::BirthYearCondition(SearchInput in) {
	this->year = stoi(in.search_pattern);

	Match = [this](Employee& in) -> bool {
		unsigned year = in.birth / 10000;
		return year == this->year;
	};
}

BirthMonthCondition::BirthMonthCondition(SearchInput in) {
	this->month = stoi(in.search_pattern);
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

BirthDayCondition::BirthDayCondition(SearchInput in) {
	this->day = stoi(in.search_pattern);
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

ClCondition::ClCondition(SearchInput in) {
	this->cl = StrToCL(in.search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.cl == this->cl;
	};
}

CertiCondition::CertiCondition(SearchInput in) {
	this->certi = StrToCerti(in.search_pattern);

	Match = [this](Employee& in) -> bool {
		return in.certi == this->certi;
	};
}

void Search::SetEmployeeList(Employees* employees_ptr) {
	this->employees_ = employees_ptr;
}

employeeList Search::DoSearch(SearchInput in) {
	employeeList searchOutput;

	switch (in.search_type)	{
	case SearchType::EMPLOYEE_NUM: 	 this->search_condition = new EmployNumCondition(in);	  break;
	case SearchType::NAME:       	 this->search_condition = new NameCondition(in);	      break;
	case SearchType::FIRST_NAME:	 this->search_condition = new FirstNameCondition(in);	  break;
	case SearchType::LAST_NAME:		 this->search_condition = new LastNameCondition(in);	  break;
	case SearchType::PHONE_NUM:  	 this->search_condition = new PhoneNumCondition(in);	  break;
	case SearchType::PHONE_NUM_MID:	 this->search_condition = new PhoneNumMidCondition(in);	  break;
	case SearchType::PHONE_NUM_LAST: this->search_condition = new PhoneNumLastCondition(in);  break;
	case SearchType::BIRTHDAY:	     this->search_condition = new BirthCondition(in);	      break;
	case SearchType::BIRTHDAY_YEAR:	 this->search_condition = new BirthYearCondition(in);	  break;
	case SearchType::BIRTHDAY_MONTH: this->search_condition = new BirthMonthCondition(in);	  break;
	case SearchType::BIRTHDAY_DAY:	 this->search_condition = new BirthDayCondition(in);	  break;
	case SearchType::CL:	         this->search_condition = new ClCondition(in);	          break;
	case SearchType::CERTI:	         this->search_condition = new CertiCondition(in);	      break;
	default: throw std::out_of_range("SearchType range error!");
	}

	searchOutput = this->employees_->Search(this->search_condition->Match);

	delete this->search_condition;

	return searchOutput;
}
