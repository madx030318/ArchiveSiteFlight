import json
from pathlib import Path

class ArchiveBridge:
    def __init__(self):
        self.data_file = Path(
            __file__
        ).parent / "name.json"
      
    def load_data(self):


      if not self.data_file.exists():
            return []
      

        with open(
            self.data_file,
            "r",
            encoding="utf-8"
        ) as file:
            return json.load(file)
    def search(self, query="", year=None, category=None, source=None):
        records = self.load_data()
        results = []
        for record in records:
            if query:
                text = json.dumps(record).lower()
                if query.lower() not in text:
                    continue
                if year:
                    if str(record.get("Year")) != str(year):
                    continue
                if category:
                    if record.get("Category") != category:
                    continue

            if source:

                if record.get("Source") != source:
                    continue

            results.append(record)
            return results


if __name__ == "__main__":

    bridge = ArchiveBridge()

    results = bridge.search()

    print(json.dumps(results, indent=4))
