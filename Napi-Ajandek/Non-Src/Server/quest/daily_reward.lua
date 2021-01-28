quest select_skill begin
	state start begin
		when login or levelup with pc.getqf("daily_reward.can_open_dreward") < get_global_time() begin
			send_letter("Napi Ajándék");
		end
		
		when button or info with pc.getqf("daily_reward.can_open_dreward") < get_global_time() begin
			command ("dailyReward_open");
		end
	end
end 