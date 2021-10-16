/*************************************************************************
 *
 * CONFIDENTIAL
 * __________________
 *
 *  2021 ALi woto
 *  All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains
 * the property of ALi woto, The intellectual and technical
 * concepts contained herein are proprietary to ALi woto
 * and his suppliers and may be covered by U.S. and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from ALi woto.
 */



#ifndef MDPARSER__WOTOMD_H
#define MDPARSER__WOTOMD_H

#include <iostream>


static __always_inline bool IsSpecial(const char value)
{
	switch (value)
	{
	case '\\':
	case '\'':
	case '*':
	case '_':
	case '{':
	case '}':
	case '[':
	case ']':
	case '(':
	case ')':
	case '#':
	case '+':
	case '-':
	case '.':
	case '!':
	case '`':
	case '=':
	case '>':
	case '<':
	case '~':
	case '|':
		return true;
	default:
		return false;
	}
}


static __always_inline std::string FixString(const std::string value)
{
	std::string finalStr = "";
	for (size_t i = 0; i < value.length(); i++)
	{
		if (IsSpecial(value[i]))
		{
			finalStr += "\\";
		}
		finalStr += value[i];
	}

	return finalStr;	
}

static __always_inline std::string toNormal(std::string value)
{
	return FixString(value);
}

static __always_inline std::string toNormal(std::string value, bool space)
{
	return FixString(value) + (space ? " " : "");
}

static __always_inline std::string toBold(std::string value)
{
	return "*" + FixString(value) + "*";
}

static __always_inline std::string toBold(std::string value, bool space)
{
	return "*" + FixString(value) + (space ? "* " : "*");
}


static __always_inline std::string toUnderline(std::string value)
{
	return "*" + FixString(value) + "*";
}

static __always_inline std::string toUnderline(std::string value, bool space)
{
	return "-" + FixString(value) + (space ? "- " : "-");
}

static __always_inline std::string toItalic(std::string value)
{
	return "_" + FixString(value) + "_";
}

static __always_inline std::string toItalic(std::string value, bool space)
{
	return "_" + FixString(value) + (space ? "_ " : "_");
}

static __always_inline std::string toMono(std::string value)
{
	return "`" + FixString(value) + "`";
}

static __always_inline std::string toMono(std::string value, bool space)
{
	return "`" + FixString(value) + (space ? "` " : "`");
}

static __always_inline std::string toHyperLink(std::string text, std::string url)
{
	return "[" + FixString(text) + "]" + "(" + FixString(url) + ")";
}

static __always_inline std::string toHyperLink(std::string text, std::string url,
	bool space)
{
	return "[" + FixString(text) + "]" + "(" + FixString(url) + 
		(space ? ") " : ")");
}


static __always_inline std::string toUserMention(std::string text, long long id)
{
	return "[" + FixString(text) + "]" + "(" + "tg://user?id=" + 
		std::to_string(id) + ")";
}

static __always_inline std::string toUserMention(std::string text, long long id,
	bool space)
{
	return "[" + FixString(text) + "]" + "(" + "tg://user?id=" + 
		std::to_string(id) + (space ? ") " : ")");
}

class WotoMd {
	public:
	WotoMd();
	WotoMd(std::string);
	WotoMd *Append(const WotoMd *value) const;
	WotoMd *AppendNormal(const std::string value) const;
	WotoMd *AppendItalic(const std::string value) const;
	WotoMd *AppendBold(const std::string value) const;
	WotoMd *AppendHyperLink(const std::string text, const std::string url) const;
	WotoMd *AppendUserMention(const std::string text, long long id) const;
	WotoMd *AppendUnderline(const std::string value) const;

	WotoMd *AppendThis(const WotoMd *value);
	WotoMd *AppendNormalThis(const std::string value);
	WotoMd *AppendItalicThis(const std::string value);
	WotoMd *AppendBoldThis(const std::string value);
	WotoMd *AppendHyperLinkThis(const std::string text, const std::string url);
	WotoMd *AppendUserMentionThis(const std::string text, long long id);
	WotoMd *AppendUnderlineThis(const std::string value);

	std::string ToString() const;

	private:
	std::string _value;
};



WotoMd *get_normal(const std::string value);
WotoMd *get_italic(const std::string value);
WotoMd *get_bold(const std::string value);
WotoMd *get_underline(const std::string value);
WotoMd *get_hyperlink(const std::string text, const std::string url);
WotoMd *get_usermention(const std::string text, const long long id);

#endif /* MDPARSER__WOTOMD_H */