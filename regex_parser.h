//
// Created by xvvx on 18-4-1.
//

#ifndef REGEXENGINE_PARSER_H
#define REGEXENGINE_PARSER_H


#include <sstream>

#include "nfa.h"
#include "dfa.h"

using std::string;
using std::stringstream;


class RegexParser {
public:
    Nfa *ParseToNfa(const string &regex){
        stringstream regex_stream(regex);
        NfaComponent *component = ParseRegex(regex_stream);
        Nfa *nfa = new Nfa(component);
        return nfa;
    }

    Dfa *ParseToDfa(const string &regex) {
        auto nfa = ParseToNfa(regex);
        auto beg_node = dfa_constructor::ConvertNfaToDfa(nfa);
        auto dfa = new Dfa(beg_node);
        return dfa;
    }


public:
    NfaComponent *ParseRegex(stringstream &regex_stream);
    NfaComponent *ParseSimpleRegex(stringstream &regex_stream);
    NfaComponent *ParseBasicRegex(stringstream &regex_stream);
    NfaComponent *ParseElementary(stringstream &regex_stream);
    NfaComponent *ParseGroup(stringstream &regex_stream);
    NfaComponent *ParseSet(stringstream &regex_stream);
    NfaComponent *ParseSetItems(stringstream &regex_stream);
    NfaComponent *ParseSetItem(stringstream &regex_stream);
    NfaComponent *ParseEscape(stringstream &regex_stream);
};


#endif //REGEXENGINE_PARSER_H
