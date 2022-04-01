#include "command.h"

Command* GetAddCommand(vector<string> input_cmd_param) {
	return new Add(input_cmd_param);
}

Command* GetDelCommand(vector<string> input_cmd_param) {
	return new Del(input_cmd_param);
}

Command* GetModCommand(vector<string> input_cmd_param) {
	return new Modify(input_cmd_param);
}

Command* GetSchCommand(vector<string> input_cmd_param) {
	return new Search(input_cmd_param);
}