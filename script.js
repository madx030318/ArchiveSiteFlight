const resultsContainer = document.getElementById("resultsContainer");

const records = [
    {
        year: 2026,
        category: "Flight",
        source: "Flight Dataset",
        departureTime: "08:30",
        arrivalTime: "11:45"
    },
    {
        year: 2026,
        category: "Flight",
        source: "Flight Dataset",
        departureTime: "14:20",
        arrivalTime: "17:10"
    }
];

function displayRecords(data)
{
    resultsContainer.innerHTML = "";

    if (data.length === 0)
    {
        resultsContainer.innerHTML = "<p>No records found.</p>";
        return;
    }

    data.forEach(record =>
    {
        const recordElement = document.createElement("div");

        recordElement.classList.add("record");

        recordElement.innerHTML = `
            <h3>${record.category}</h3>

            <p>Year: ${record.year}</p>
            <p>Source: ${record.source}</p>
            <p>Departure: ${record.departureTime}</p>
            <p>Arrival: ${record.arrivalTime}</p>
        `;

        resultsContainer.appendChild(recordElement);
    });
}

displayRecords(records);
