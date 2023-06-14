#include <string>
#include <string_view>

std::string replace(std::string source, std::string_view from, std::string_view to) {
	std::string::size_type pos = source.find(from);
	std::string::size_type length = from.size();

	while (pos != std::string::npos) {
		source.replace(pos, length, to);
		pos = source.find(from, pos + 1);
	}

	return source;
}
