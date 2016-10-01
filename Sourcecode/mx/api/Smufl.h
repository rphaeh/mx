// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include <string>
#include <map>

namespace mx
{
    namespace api
    {
        using SmuflPair = std::pair<const std::string, const char16_t>;
        using SmuflMap = std::map<const std::string, const char16_t>;
        using SmuflIter = SmuflMap::const_iterator;
        
        class Smufl
        {

        public:
            
            // returns the SMuFL codepoint value for the given name
            // returns 0 (i.e. '\0;) if not found
            static char16_t findCodepoint(const std::string& inName);
            
            // finds the SMuFL glyphname for the given codepoint
            // returns empty string if codepoint is not found
            static const std::string& findName( char16_t codepoint );
            
            // returns 'true' if the given name is found in the table
            static bool isNameValid(const std::string& inName);
            
            // returns 'true' if the given codepoint is found
            // in the table. ignores alternateCodepoint values
            static bool isCodepointValid( char16_t codepoint );
            
            // returns an immutable ref to the map
            static const SmuflMap& getMap();
            
            // returns cbegin() / cend()
            static SmuflIter begin();
            static SmuflIter end();
            
        private:
            Smufl();
            static const Smufl& instance();
            std::map<const std::string, const char16_t> myMap;
        };
    }
}