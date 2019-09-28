import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        k = datetime.date(year, month, day).weekday()
        days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
        return days[k]