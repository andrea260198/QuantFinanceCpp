#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <string>


template<class TIndex, class TCols, class TData>
class DataFrame
{
public:
    DataFrame(std::vector<TIndex> index, std::vector<TCols> columns, std::vector<std::vector<TData>> data)
        : mIndex(index)
        , mColumns(columns)
        , mData(data)
    {

    }
    
    // Copy constructor
    DataFrame(const DataFrame<TIndex, TCols, TData> &df)
        : mIndex(df.mIndex)
        , mColumns(df.mColumns)
        , mData(df.mData)
    {
        std::cout << "df is copy constructed\n";
    }

    // Move constructor
    DataFrame(const DataFrame<TIndex, TCols, TData> &&df)
        : mIndex(  std::move(df.mIndex))
        , mColumns(std::move(df.mColumns))
        , mData(   std::move(df.mData))
    {
        std::cout << "df is move constructed\n";
    }

    std::vector<TData> iloc(const int row_n)
    {
        return mData[row_n];
    }

    TData iloc(const int row_n, const int columns_n)
    {
        return mData[row_n][columns_n];
    }

    void append(const DataFrame<TIndex, TCols, TData> df)
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
    std::vector<TIndex> mIndex;
    std::vector<TCols> mColumns;
    std::vector<std::vector<TData>> mData;
};


template<class TIndex, class TCols, class TData>
std::string DataFrame<TIndex, TCols, TData>::toString()
{
    std::string df_str;

    // Print column names
    df_str += "\nDataFrame:\nColumns = ";

    for (int j = 0; j < mColumns.size(); j++)
    {
        auto columnName = mColumns[j];

        if constexpr (std::is_same_v<TCols, std::string>)
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
        if constexpr (std::is_same_v<TIndex, std::string>)
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

