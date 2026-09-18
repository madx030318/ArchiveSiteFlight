import pandas as pd
import numpy as np
from sklearn import train_test_split
import matplotlib.pyplot as plt

input_data = pd.read_csv(r"flights.csv")
input_data["Year"] = input_data["Year"].replace(2008, 2026)


input_data["DepTime"] = pd.to_numeric(input_data["DepTime"], errors = "coerce")

input_data["DepTime"] = df["DepTime"].apply( lambda x: f"{int(x):04d}" if pd.notna(x) else None)

input_data["DepTime"] = pd.to_datetime(input_data["DepTime"], format="%H%M", errors="coerce").dt.time

input_data["CRSDepTime"] = pd.to_numeric( df["CRSDepTime"], errors="coerce")

input_data["CRSDepHour"] = ( input_data["CRSDepTime"] // 100)


input_data["ArrTime"] = pd.to_numeric(df["ArrTime"], errors="coerce")

input_data["ArrTimeF"] = input_data["ArrTime"].apply(lambda x: f"{int(x):04d}" if pd.notna(x) else None)

input_data["ArrTimeF"] = pd.to_datetime(input_data["ArrTimeF"], format="%H%M", errors="coerce").dt.strftime("%H:%M")



input_data["CarrierDelay"] = pd.to_numeric(input_data["CarrierDelay"], errors="coerce")

input_data["CarrierDelayClean"] = input_data["CarrierDelay"].fillna(0)


def categorize_delay(x):
    if x == 0:
        return "No Delay"
    elif x <= 15:
        return "Short Delay"
    elif x <= 60:
        return "Moderate Delay"
    else:
        return "Long Delay"

input_data["CarrierDelayCategory"] = input_data["CarrierDelayClean"].apply(
    categorize_delay
)
