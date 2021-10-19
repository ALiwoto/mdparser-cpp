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


#include <iostream>
#include "WotoMd.h"

//---------------------------------------------------------

namespace mdparser
{

/// Creates an empty WotoMd object.
WotoMd::WotoMd()
{

}

/// Creates a new instance of WotoMd with the given string value.
WotoMd::WotoMd(const std::string value)
{
	this->_value = value;
}

/// Appends a WotoMd object to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::Append(const WotoMd *value) const {
	if (value == NULL)
	{
		return new WotoMd(value->_value);
	}
	return new WotoMd(this->_value + value->_value);
}

/// Appends a normal string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendNormal(const std::string value) const {
	return new WotoMd(this->_value + toNormal(value));
}

/// Appends a normal string to the current object and return a new
/// WotoMd object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendNormal(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toNormal(value, space));
}

/// Appends an italic string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendItalic(const std::string value) const {
	return new WotoMd(this->_value + toItalic(value));
}

WotoMd *WotoMd::AppendItalic(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toItalic(value, space));
}

/// Appends a mono string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendMono(const std::string value) const {
	return new WotoMd(this->_value + toMono(value));
}

WotoMd *WotoMd::AppendMono(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toMono(value, space));
}

/// Appends a bold string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendBold(const std::string value) const {
	return new WotoMd(this->_value + toBold(value));
}

WotoMd *WotoMd::AppendBold(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toBold(value, space));
}

/// Appends a hyper link string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendHyperLink(const std::string text, const std::string url) const {
	return new WotoMd(this->_value + toHyperLink(text, url));
}


WotoMd *WotoMd::AppendHyperLink(const std::string text, const std::string url,
	const bool space) const {
	return new WotoMd(this->_value + toHyperLink(text, url, space));
}

/// Appends a user mention string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendUserMention(const std::string text, long long id) const {
	return new WotoMd(this->_value + toUserMention(text, id));
}

WotoMd *WotoMd::AppendUserMention(const std::string text, long long id,
	const bool space) const {
	return new WotoMd(this->_value + toUserMention(text, id, space));
}

WotoMd *WotoMd::AppendUnderline(const std::string value) const {
	return new WotoMd(this->_value + toUnderline(value));
}


WotoMd *WotoMd::AppendUnderline(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toUnderline(value, space));
}

WotoMd *WotoMd::AppendThis(const WotoMd *value) {
	if (value != NULL)
	{
		this->_value += value->_value;
	}
	return this;
}


WotoMd *WotoMd::AppendNormalThis(const std::string value) {
	this->_value += toNormal(value);
	return this;
}

WotoMd *WotoMd::AppendNormalThis(const std::string value, const bool space) {
	this->_value += toNormal(value, space);
	return this;
}

WotoMd *WotoMd::AppendItalicThis(const std::string value) {
	this->_value += toItalic(value);
	return this;
}


WotoMd *WotoMd::AppendItalicThis(const std::string value, const bool space) {
	this->_value += toItalic(value, space);
	return this;
}

WotoMd *WotoMd::AppendMonoThis(const std::string value) {
	this->_value += toMono(value);
	return this;
}


WotoMd *WotoMd::AppendMonoThis(const std::string value, const bool space) {
	this->_value += toMono(value, space);
	return this;
}

WotoMd *WotoMd::AppendBoldThis(const std::string value) {
	this->_value += toBold(value);
	return this;
}


WotoMd *WotoMd::AppendBoldThis(const std::string value, const bool space) {
	this->_value += toBold(value, space);
	return this;
}

WotoMd *WotoMd::AppendHyperLinkThis(const std::string text, const std::string url) {
	this->_value += toHyperLink(text, url);
	return this;
}


WotoMd *WotoMd::AppendUserMentionThis(const std::string text, const long long id) {
	this->_value += toUserMention(text, id);
	return this;
}


WotoMd *WotoMd::AppendUserMentionThis(const std::string text, const long long id,
	const bool space) {
	this->_value += toUserMention(text, id, space);
	return this;
}

WotoMd *WotoMd::AppendUnderlineThis(const std::string value) {
	this->_value += toUnderline(value);
	return this;
}

WotoMd *WotoMd::AppendUnderlineThis(const std::string value, const bool space) {
	this->_value += toUnderline(value, space);
	return this;
}

std::string WotoMd::ToString() const {
	return this->_value;
}

//---------------------------------------------------------

WotoMd *get_normal(const std::string value) {
	return new WotoMd(toNormal(value));
}

WotoMd *get_italic(const std::string value) {
	return new WotoMd(toItalic(value));
}

WotoMd *get_mono(const std::string value) {
	return new WotoMd(toMono(value));
}

WotoMd *get_bold(const std::string value) {
	return new WotoMd(toBold(value));
}

WotoMd *get_underline(const std::string value) {
	return new WotoMd(toUnderline(value));
}

WotoMd *get_hyperlink(const std::string text, const std::string url) {
	return new WotoMd(toHyperLink(text, url));
}

WotoMd *get_usermention(const std::string text, const long long id) {
	return new WotoMd(toUserMention(text, id));
}

} // namespace mdparser
