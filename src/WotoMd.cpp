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


#include <string>
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

/// Clears the value of this WotoMd object and returns itself.
WotoMd *WotoMd::Clear()
{
	this->_value = "";
	return this;
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

/// Appends an italic string to the current object and return a new
/// WotoMd object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendItalic(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toItalic(value, space));
}

/// Appends a mono string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendMono(const std::string value) const {
	return new WotoMd(this->_value + toMono(value));
}

/// Appends a mono string to the current object and return a new
/// WotoMd object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendMono(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toMono(value, space));
}

/// Appends a bold string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendBold(const std::string value) const {
	return new WotoMd(this->_value + toBold(value));
}

/// Appends a bold string to the current object and return a new
/// WotoMd object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendBold(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toBold(value, space));
}

/// Appends a hyper link string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendHyperLink(const std::string text, const std::string url) const {
	return new WotoMd(this->_value + toHyperLink(text, url));
}

/// Appends a hyper link string to the current object and return a new
/// WotoMd object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendHyperLink(const std::string text, const std::string url,
	const bool space) const {
	return new WotoMd(this->_value + toHyperLink(text, url, space));
}

/// Appends a user mention string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendUserMention(const std::string text, const long long id) const {
	return new WotoMd(this->_value + toUserMention(text, id));
}

/// Appends a user mention string to the current object and return a new
/// WotoMd object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendUserMention(const std::string text, const long long id,
	const bool space) const {
	return new WotoMd(this->_value + toUserMention(text, id, space));
}

/// Appends an italic string to the current object and return a new
/// WotoMd object.
WotoMd *WotoMd::AppendUnderline(const std::string value) const {
	return new WotoMd(this->_value + toUnderline(value));
}

/// Appends an underline string to the current object and return a new
/// WotoMd object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendUnderline(const std::string value, const bool space) const {
	return new WotoMd(this->_value + toUnderline(value, space));
}


/// Appends a new line to the current value of this object and returns 
/// itself.
WotoMd *WotoMd::Endl() const {
	return this->AppendNormal("\n");
}

/// Appends a new line to the current value of this object and returns 
/// itself.
WotoMd *WotoMd::Space() const {
	return this->AppendNormal(" ");
}

/// Appends a new line to the current value of this object and returns 
/// itself.
WotoMd *WotoMd::Space(const int count) const {
	return this->AppendNormal(std::string(count, ' '));
}

/// Appends a WotoMd object to the current object.
WotoMd *WotoMd::AppendThis(const WotoMd *value) {
	if (value != NULL)
	{
		this->_value += value->_value;
	}
	return this;
}

/// Appends a normal string to the current object.
WotoMd *WotoMd::AppendNormalThis(const std::string value) {
	this->_value += toNormal(value);
	return this;
}

/// Appends a normal string to the current object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendNormalThis(const std::string value, const bool space) {
	this->_value += toNormal(value, space);
	return this;
}

/// Appends an italic string to the current object.
WotoMd *WotoMd::AppendItalicThis(const std::string value) {
	this->_value += toItalic(value);
	return this;
}

/// Appends an italic string to the current object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendItalicThis(const std::string value, const bool space) {
	this->_value += toItalic(value, space);
	return this;
}

/// Appends a mono string to the current object.
WotoMd *WotoMd::AppendMonoThis(const std::string value) {
	this->_value += toMono(value);
	return this;
}

/// Appends a mono string to the current object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendMonoThis(const std::string value, const bool space) {
	this->_value += toMono(value, space);
	return this;
}

/// Appends a bold string to the current object.
WotoMd *WotoMd::AppendBoldThis(const std::string value) {
	this->_value += toBold(value);
	return this;
}

/// Appends a bold string to the current object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendBoldThis(const std::string value, const bool space) {
	this->_value += toBold(value, space);
	return this;
}

/// Appends a hyper link string to the current object.
WotoMd *WotoMd::AppendHyperLinkThis(const std::string text, const std::string url) {
	this->_value += toHyperLink(text, url);
	return this;
}


/// Appends a bold string to the current object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendHyperLinkThis(const std::string text, const std::string url,
	const bool space) {
	this->_value += toHyperLink(text, url, space);
	return this;
}

/// Appends a user mention value to the current object.
WotoMd *WotoMd::AppendUserMentionThis(const std::string text, const long long id) {
	this->_value += toUserMention(text, id);
	return this;
}

/// Appends a user mention value to the current object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendUserMentionThis(const std::string text, const long long id,
	const bool space) {
	this->_value += toUserMention(text, id, space);
	return this;
}

/// Appends a hyper link string to the current object.
WotoMd *WotoMd::AppendUnderlineThis(const std::string value) {
	this->_value += toUnderline(value);
	return this;
}

/// Appends an underline value to the current object.
/// Pass true to second parameter to append a space at the end of the string.
WotoMd *WotoMd::AppendUnderlineThis(const std::string value, const bool space) {
	this->_value += toUnderline(value, space);
	return this;
}

/// Appends a new line to the current value of this object and returns 
/// itself.
WotoMd *WotoMd::EndlThis() {
	return this->AppendNormalThis("\n");
}

/// Appends a new line to the current value of this object and returns 
/// itself.
WotoMd *WotoMd::SpaceThis() {
	return this->AppendNormalThis(" ");
}

/// Appends a new line to the current value of this object and returns 
/// itself.
WotoMd *WotoMd::SpaceThis(const int count) {
	return this->AppendNormal(std::string(count, ' '));
}

/// Converts the current WotoMd object to string value.
std::string WotoMd::ToString() const {
	return this->_value;
}


//---------------------------------------------------------

/// get a WotoMd object from a normal string.
WotoMd *get_normal(const std::string value) {
	return new WotoMd(toNormal(value));
}

/// get a WotoMd object from an italic string.
WotoMd *get_italic(const std::string value) {
	return new WotoMd(toItalic(value));
}

/// get a WotoMd object from a mono string.
WotoMd *get_mono(const std::string value) {
	return new WotoMd(toMono(value));
}

/// get a WotoMd object from a bold string.
WotoMd *get_bold(const std::string value) {
	return new WotoMd(toBold(value));
}

/// get a WotoMd object from an underline string.
WotoMd *get_underline(const std::string value) {
	return new WotoMd(toUnderline(value));
}

/// get a hyperlink-styled WotoMd object from a string.
WotoMd *get_hyperlink(const std::string text, const std::string url) {
	return new WotoMd(toHyperLink(text, url));
}

/// get a usermention-styled WotoMd object from a string.
WotoMd *get_usermention(const std::string text, const long long id) {
	return new WotoMd(toUserMention(text, id));
}

} // namespace mdparser
