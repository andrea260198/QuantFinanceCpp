#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <string>


template<class T0, class T1, class T2>
class DataFrame
{
public:
    DataFrame(std::vector<T0> index, std::vector<T1> columns, std::vector<std::vector<T2>> data)
        : mIndex(index)
        , mColumns(columns)
        , mData(data)
    {

    }
	
	// Copy constructor
	DataFrame(const DataFrame<T0, T1, T2> &df)
		: mIndex(df.mIndex)
		, mColumns(df.mColumns)
		, mData(df.mData)
	{
		std::cout << "df is copy constructed\n";
	}

	std::vector<T2> iloc(const int row_n)
	{
		return mData[row_n];
	}

    T2 iloc(const int row_n, const int columns_n)
	{
		return mData[row_n][columns_n];
	}

    void append(const DataFrame<T0, T1, T2> df)
	{
		if (df.mColumns == mColumns)
		{
            mIndex.insert(std::end(mIndex), std::begin(df.mIndex), std::end(df.mIndex));
            mData.insert(std::end(mData), std::begin(df.mData), std::end(df.mData));
        } else
        {
            throw std::invalid_argument("Columns mismatch");
        }
	}

    std::string toString();
	
private:
	std::vector<T0> mIndex;
	std::vector<T1> mColumns;
	std::vector<std::vector<T2>> mData;
};


template<class T0, class T1, class T2>
std::string DataFrame<T0, T1, T2>::toString()
{
    std::string df_str;

    // Print column names
    df_str += "\nDataFrame:\nColumns = ";

    for (int j = 0; j < mColumns.size(); j++)
    {
        auto columnName = mColumns[j];

        if constexpr (std::is_same_v<T1, std::string>)
        {
            df_str += columnName;
        } else
        {
            df_str += std::to_string(columnName);
        }

        if (j < mColumns.size() - 1)
        {
            df_str += ", ";
        }
    }
    df_str += "\n";


    for (int i = 0; i < mData.size(); i++)
    {
        auto row = mData[i];

        // Print row index
        if constexpr (std::is_same_v<T0, std::string>)
        {
            df_str += mIndex[i] + ": ";
        } else
        {
             df_str += std::to_string(mIndex[i]) + ": ";
        }

        // Print row data
        for (int j = 0; j < row.size(); j++)
        {
            df_str += std::to_string(row[j]);
            if (j < row.size() - 1)
            {
                df_str += ", ";
            }
        }
        df_str += "\n";
    }
    return df_str;
}

