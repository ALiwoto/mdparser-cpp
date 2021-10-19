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

#pragma once

#include <string>

namespace mdparser
{

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

static __always_inline std::string toNormal(const std::string value)
{
	return FixString(value);
}

static __always_inline std::string toNormal(const std::string value, 
					    const bool space)
{
	return FixString(value) + (space ? " " : "");
}

static __always_inline std::string toBold(const std::string value)
{
	return "*" + FixString(value) + "*";
}

static __always_inline std::string toBold(const std::string value, 
					  const bool space)
{
	return "*" + FixString(value) + (space ? "* " : "*");
}

static __always_inline std::string toUnderline(const std::string value)
{
	return "-" + FixString(value) + "-";
}

static __always_inline std::string toUnderline(const std::string value,
					       const bool space)
{
	return "-" + FixString(value) + (space ? "- " : "-");
}

static __always_inline std::string toItalic(const std::string value)
{
	return "_" + FixString(value) + "_";
}

static __always_inline std::string toItalic(const std::string value, 
					    const bool space)
{
	return "_" + FixString(value) + (space ? "_ " : "_");
}

static __always_inline std::string toMono(const std::string value)
{
	return "`" + FixString(value) + "`";
}

static __always_inline std::string toMono(const std::string value,
	const bool space)
{
	return "`" + FixString(value) + (space ? "` " : "`");
}

static __always_inline std::string toHyperLink(const std::string text,
	const std::string url)
{
	return "[" + FixString(text) + "]" + "(" + FixString(url) + ")";
}

static __always_inline std::string toHyperLink(const std::string text,
					       const std::string url, bool space)
{
	return "[" + FixString(text) + "]" + "(" + FixString(url) + 
		(space ? ") " : ")");
}


static __always_inline std::string toUserMention(const std::string text,
						 const long long id)
{
	return "[" + FixString(text) + "]" + "(" + "tg://user?id=" + 
		std::to_string(id) + ")";
}

static __always_inline std::string toUserMention(const std::string text,
						 const long long id,
						 const bool space)
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
	WotoMd *AppendNormal(const std::string value, const bool space) const;
	WotoMd *AppendItalic(const std::string value) const;
	WotoMd *AppendItalic(const std::string value, const bool space) const;
	WotoMd *AppendMono(const std::string value) const;
	WotoMd *AppendMono(const std::string value, const bool space) const;
	WotoMd *AppendBold(const std::string value) const;
	WotoMd *AppendBold(const std::string value, const bool space) const;
	WotoMd *AppendHyperLink(const std::string text, const std::string url) const;
	WotoMd *AppendHyperLink(const std::string text, const std::string url,
				const bool space) const;
	WotoMd *AppendUserMention(const std::string text, const long long id) const;
	WotoMd *AppendUserMention(const std::string text, const long long id,
				  const bool space) const;
	WotoMd *AppendUnderline(const std::string value) const;
	WotoMd *AppendUnderline(const std::string value, const bool space) const;
	WotoMd *Endl() const;
	WotoMd *Space() const;
	WotoMd *Space(const int count) const;

	WotoMd *AppendThis(const WotoMd *value);
	WotoMd *AppendNormalThis(const std::string value);
	WotoMd *AppendNormalThis(const std::string value, const bool space);
	WotoMd *AppendItalicThis(const std::string value);
	WotoMd *AppendItalicThis(const std::string value, const bool space);
	WotoMd *AppendMonoThis(const std::string value);
	WotoMd *AppendMonoThis(const std::string value, const bool space);
	WotoMd *AppendBoldThis(const std::string value);
	WotoMd *AppendBoldThis(const std::string value, const bool space);
	WotoMd *AppendHyperLinkThis(const std::string text, const std::string url);
	WotoMd *AppendHyperLinkThis(const std::string text, const std::string url,
				    const bool space);
	WotoMd *AppendUserMentionThis(const std::string text, const long long id);
	WotoMd *AppendUserMentionThis(const std::string text, const long long id,
				      const bool space);
	WotoMd *AppendUnderlineThis(const std::string value);
	WotoMd *AppendUnderlineThis(const std::string value, const bool space);
	WotoMd *EndlThis();
	WotoMd *SpaceThis();
	WotoMd *SpaceThis(const int count);

	std::string ToString() const;
	WotoMd *Clear();

	private:
	std::string _value;
};



WotoMd *get_normal(const std::string value);
WotoMd *get_italic(const std::string value);
WotoMd *get_mono(const std::string value);
WotoMd *get_bold(const std::string value);
WotoMd *get_underline(const std::string value);
WotoMd *get_hyperlink(const std::string text, const std::string url);
WotoMd *get_usermention(const std::string text, const long long id);

} // namespace mdparser
