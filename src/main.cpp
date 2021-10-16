#include <iostream>
#include "WotoMd.cpp"

int main() {
	auto md = get_bold("test for bold!\n");
	md = md->AppendHyperLink("and this a hyper link!", "google.com");
	md->AppendItalicThis("and an italic text...");
	md->AppendUserMentionThis("user mention", 12345678910);
	std::cout << "test" "huhuhu\n" << md->ToString();
	return 0;
}