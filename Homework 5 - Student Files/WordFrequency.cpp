///////////////////////// TO-DO (1) //////////////////////////////
  /// Include necessary header files
  /// Hint:  Include what you use, use what you include
  ///
  /// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives
#include <cctype>
#include <cstddef>
#include <iostream>
#include <locale>
#include <string>
#include <unordered_map>

#include "WordFrequency.hpp"
/////////////////////// END-TO-DO (1) ////////////////////////////







// unnamed, anonymous namespace providing non-member private working area
namespace
{
  std::string sanitize( const std::string & word )
  {
    constexpr char bad_char[] = " \t\r\n\b\v_-\"'(){}+/*,=.!?:;";          // leading and trailing characters to be removed
    static std::locale locality{ "en_GB.UTF-8" };

    auto startIndex = word.find_first_not_of( bad_char );                  // start with the first non-bad character
    if( startIndex == std::string::npos ) startIndex = word.size();        // if the word contains only bad characters ...

    std::size_t count    = 0;                                              // assume the word contains only bad characters ...
    auto        endIndex = word.find_last_not_of( bad_char );              // end with the first non-bad character

    if( endIndex != std::string::npos ) count = endIndex - startIndex + 1; // number of characters to use in results

    auto result = word.substr( startIndex, count );                        // strip the leading and trailing bad characters
    for( auto & c : result ) c = std::tolower( c, locality );              // convert to lower case

    return result;
  }
}  // unnamed, anonymous namespace







// Implement WordFrequency::WordFrequency( std::istream ) - See requirements
///////////////////////// TO-DO (2) //////////////////////////////
WordFrequency::WordFrequency( std::istream & iStream )
{
  std::string word{};
  while( iStream >> word )
  {
    _wordMap[sanitize( word )] += 1;
  }
}
/////////////////////// END-TO-DO (2) ////////////////////////////







// Implement WordFrequency::numberOfWords() const - See requirements
///////////////////////// TO-DO (3) //////////////////////////////
std::size_t WordFrequency::numberOfWords() const
{
  return _wordMap.size();
}
/////////////////////// END-TO-DO (3) ////////////////////////////







// Implement WordFrequency::wordCount( const std::string & ) const - See requirements
///////////////////////// TO-DO (4) //////////////////////////////
std::size_t WordFrequency::wordCount( const std::string & wordInput) const
{
  const auto& wordIt = _wordMap.find( sanitize( wordInput ) );
  if( wordIt == _wordMap.end() ) return 0;
  return wordIt->second;
}
/////////////////////// END-TO-DO (4) ////////////////////////////







// Implement WordFrequency::mostFrequentWord() const - See requirements
///////////////////////// TO-DO (5) //////////////////////////////
std::string WordFrequency::mostFrequentWord() const
{
  std::size_t currentHighestFrequency = 0;
  const std::string* currentMostFrequentWord = nullptr;

  for ( const auto& word : _wordMap )
  {
    if ( word.second > currentHighestFrequency )
    {
      currentMostFrequentWord = &word.first;
      currentHighestFrequency = word.second;
    }
  }

  if ( currentMostFrequentWord == nullptr ) return "";

  return *currentMostFrequentWord;
}

/////////////////////// END-TO-DO (5) ////////////////////////////







// Implement WordFrequency::maxBucketSize() const - See requirements
///////////////////////// TO-DO (6) //////////////////////////////
  /// Hint: see the unordered_map's bucket interface at https://en.cppreference.com/w/cpp/container/unordered_map
std::size_t WordFrequency::maxBucketSize() const
{
  std::size_t maxBucketSize = 0;
  for( std::size_t i = 0; i < _wordMap.bucket_count(); ++i )
  {
    const std::size_t currentBucketSize = _wordMap.bucket_size( i );

    if ( currentBucketSize > maxBucketSize ) maxBucketSize = currentBucketSize;
  }

  return maxBucketSize;
}
/////////////////////// END-TO-DO (6) ////////////////////////////
